#include "WebServer.h"

// CTOR
WebServer::WebServer()
{
    _server = NULL;
}

/**
 * @brief Start the webserver, when it is not already started
 * 
 * @param config the configuration that will be used for the server
 * @return esp_err_t the status of the operation
 */
esp_err_t WebServer::startWebserver(httpd_config_t* config) 
{
    if (_server){
        return ESP_ERR_INVALID_STATE;
    }

    httpd_config_t serverConfig;

    if (config == nullptr) {
        serverConfig = HTTPD_DEFAULT_CONFIG();
    }
    else{
        serverConfig = *config;
    }

    return httpd_start(&_server, config);
}

/**
 * @brief Stop the webserver, when it is running
 * 
 * @return esp_err_t the status of the operation
 */
esp_err_t WebServer::stopWebserver() 
{
    if (!_server){
        return ESP_ERR_INVALID_STATE;
    }

    return httpd_stop(_server);
}

/**
 * @brief register a specific uri on the web server
 * 
 * @param uri_handler the data used for the handler
 * @return esp_err_t the status of the operation
 */
esp_err_t WebServer::registerUriHandler(httpd_uri_t* uri_handler) 
{
    /* fail when server is not started */
    if (!_server){
        return ESP_ERR_INVALID_STATE;
    }

    return httpd_register_uri_handler(_server, uri_handler);
}

/**
 * @brief register for notification about specific errords
 * 
 * @param errorCode the code for the error to listen for
 * @param errorFunction the callback function, that will be invoked
 * @return esp_err_t the status of the operation
 */
esp_err_t WebServer::registerErrHandler(httpd_err_code_t errorCode, httpd_err_handler_func_t errorFunction) 
{
    /* fail when server is not started */
    if (!_server){
        return ESP_ERR_INVALID_STATE;
    }

    return httpd_register_err_handler(_server, errorCode, errorFunction);
}
