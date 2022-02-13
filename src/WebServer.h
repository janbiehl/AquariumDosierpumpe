#ifndef B206D4F4_8BE9_40BC_8115_5338718F9D20
#define B206D4F4_8BE9_40BC_8115_5338718F9D20

#include <esp_http_server.h>

/**
 * @brief Represents a webserver
 * 
 */
class WebServer
{
private:

    /* server handle */
    httpd_handle_t _server;

public:
    /* ctor */
    WebServer();

    /* start the webserver */
    esp_err_t startWebserver(httpd_config_t* config);
    /* stop the webserver */
    esp_err_t stopWebserver();
    /* register for a specific uri */
    esp_err_t registerUriHandler(httpd_uri_t* data);
    /* register for a specific error */
    esp_err_t registerErrHandler(httpd_err_code_t errorCode, httpd_err_handler_func_t errorFunction);
};

#endif /* B206D4F4_8BE9_40BC_8115_5338718F9D20 */
