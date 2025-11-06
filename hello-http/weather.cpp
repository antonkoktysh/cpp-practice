#include "weather.h"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

#include <Poco/URI.h>

#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>

class TForecaster : public IForecaster {
public:
    TForecaster(const std::string& api_key, const std::string& api_endpoint)
        : api_key_(api_key), api_endpoint_(api_endpoint) {
    }

    WeatherForecast ForecastWeather(std::optional<Location> where) override {
        Poco::URI uri(api_endpoint_);
        if (where) {
            uri.addQueryParameter("lat", Poco::format("%.2f", where->lat));
            uri.addQueryParameter("lon", Poco::format("%.2f", where->lon));
        }
        Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
        Poco::Net::HTTPRequest request("GET", uri.toString());
        request.add("X-Yandex-API-Key", api_key_);
        session.sendRequest(request);
        Poco::Net::HTTPResponse response;
        auto& body = session.receiveResponse(response);
        if (response.getStatus() / 100 != 2) {
            throw YandexAPIError(response.getStatus(), "server error");
        }
        Poco::JSON::Parser parser;
        auto reply = parser.parse(body);
        auto fact = reply.extract<Poco::JSON::Object::Ptr>()->getObject("fact");
        return WeatherForecast{.temp = fact->getValue<double>("temp"),
                               .feels_like = fact->getValue<double>("feels_like")};
    }

private:
    std::string api_key_;
    std::string api_endpoint_;
};

std::unique_ptr<IForecaster> CreateYandexForecaster(const std::string& api_key,
                                                    const std::string& api_endpoint) {
    return std::make_unique<TForecaster>(api_key, api_endpoint);
}