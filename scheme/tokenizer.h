#pragma once

#include <variant>
#include <istream>
#include <string>

struct SymbolToken {
    std::string name;
    SymbolToken(const std::string& name) : name(name) {
    }
    SymbolToken(std::string&& name) : name(std::move(name)) {
    }
    SymbolToken(char c) : name(1, c) {
    }
    bool operator==(const SymbolToken& other) const {
        return name == other.name;
    }
};

struct QuoteToken {
    bool operator==(const QuoteToken&) const {
        return true;
    }
};

struct DotToken {
    bool operator==(const DotToken&) const {
        return true;
    }
};

enum class BracketToken { OPEN, CLOSE };

struct ConstantToken {
    int value;
    ConstantToken() = default;
    ConstantToken(int value) : value(value) {
    }
    ConstantToken(const std::string& str) {
        value = std::stoi(str);
    }
    bool operator==(const ConstantToken& other) const {
        return value == other.value;
    }
};

using Token = std::variant<ConstantToken, BracketToken, SymbolToken, QuoteToken, DotToken>;

// Интерфейс, позволяющий читать токены по одному из потока.
class Tokenizer {
public:
    Tokenizer(std::istream* in) : in_(in), is_end_(false) {
        Next();
    }

    bool IsEnd() const {
        return is_end_;
    }

    void Next() {
        while (in_->peek() != EOF && (in_->peek() == ' ' || in_->peek() == '\n')) {
            in_->get();
        }
        if (in_->peek() == EOF) {
            is_end_ = true;
        }
        while (in_->peek() != EOF) {
            if (in_->peek() == ' ' || in_->peek() == '\n') {
                in_->get();
                continue;
            } else if (in_->peek() == '(') {
                token_.emplace<BracketToken>(BracketToken::OPEN);
                ++open_;
                in_->get();
                break;
            } else if (in_->peek() == ')') {
                token_.emplace<BracketToken>(BracketToken::CLOSE);
                ++close_;
                in_->get();
                break;
            } else if (in_->peek() == '.') {
                token_.emplace<DotToken>(DotToken());
                in_->get();
                break;
            } else if (in_->peek() == '\'') {
                token_.emplace<QuoteToken>(QuoteToken());
                in_->get();
                break;
            } else if (in_->peek() == '-') {
                in_->get();
                if (isspace(in_->peek()) || !isdigit(in_->peek())) {
                    token_.emplace<SymbolToken>(SymbolToken("-"));
                    break;
                } else {
                    std::string num = "-";
                    while (in_->peek() != EOF && isdigit(in_->peek())) {
                        num.push_back(in_->get());
                    }
                    token_.emplace<ConstantToken>(ConstantToken(num));
                    break;
                }
            } else if (in_->peek() == '+') {
                in_->get();
                if (isspace(in_->peek()) || (!isdigit(in_->peek()))) {
                    token_.emplace<SymbolToken>(SymbolToken("+"));
                    break;
                } else {
                    std::string num;
                    while (in_->peek() != EOF && isdigit(in_->peek())) {
                        num.push_back(in_->get());
                    }
                    token_.emplace<ConstantToken>(ConstantToken(num));
                    break;
                }
            } else if (isdigit(in_->peek())) {
                std::string num;
                while (in_->peek() != EOF && isdigit(in_->peek())) {
                    num.push_back(in_->get());
                }
                token_.emplace<ConstantToken>(ConstantToken(num));
                break;
            } else {
                std::string special_characters = "<=>*/#?!-";
                std::string word;
                while (in_->peek() != EOF && !isspace(in_->peek()) &&
                       (isalpha(in_->peek()) || isdigit(in_->peek()) ||
                        special_characters.find(in_->peek()) != std::string::npos)) {
                    word.push_back(in_->get());
                }
                token_.emplace<SymbolToken>(SymbolToken(word));
                break;
            }
        }
    }

    Token GetToken() const {
        return token_;
    }

    size_t GetOpen() const {
        return open_;
    }

    size_t GetClose() const {
        return close_;
    }

private:
    Token token_;
    std::istream* in_;
    bool is_end_;
    size_t open_ = 0U;
    size_t close_ = 0U;
};
