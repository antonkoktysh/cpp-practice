function(link_poco NAME)
  link_directories(/opt/homebrew/Cellar/poco/1.14.0/lib)
  include_directories(/opt/homebrew/Cellar/poco/1.14.0/include)
  target_link_libraries(${NAME} PRIVATE 
    /opt/homebrew/Cellar/poco/1.14.0/lib/libPocoNet.dylib
    /opt/homebrew/Cellar/poco/1.14.0/lib/libPocoNetSSL.dylib
    /opt/homebrew/Cellar/poco/1.14.0/lib/libPocoFoundation.dylib
    /opt/homebrew/Cellar/poco/1.14.0/lib/libPocoJSON.dylib
    /opt/homebrew/Cellar/poco/1.14.0/lib/libPocoUtil.dylib)
endfunction()

add_catch(test_hello_http test.cpp fake/fake_data.cpp weather.cpp)
link_poco(test_hello_http)

add_shad_executable(hello_http weather.cpp main.cpp)
link_poco(hello_http)
