/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.11.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include <corvusoft/restbed/byte.hpp>
#include <corvusoft/restbed/string.hpp>
#include <corvusoft/restbed/settings.hpp>
#include <corvusoft/restbed/request.hpp>
#include <corvusoft/restbed/uri.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "StoreApi.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

namespace {
[[maybe_unused]]
std::string selectPreferredContentType(const std::vector<std::string>& contentTypes) {
    if (contentTypes.size() == 0) {
        return "application/json";
    }

    if (contentTypes.size() == 1) {
        return contentTypes.at(0);
    }

    static const std::array<std::string, 2> preferredTypes = {"json", "xml"};
    for (const auto& preferredType: preferredTypes) {
        const auto ret = std::find_if(contentTypes.cbegin(),
        contentTypes.cend(),
        [preferredType](const std::string& str) {
            return str.find(preferredType) != std::string::npos;});
        if (ret != contentTypes.cend()) {
            return *ret;
        }
    }

    return contentTypes.at(0);
}
}

StoreApiException::StoreApiException(int status_code, std::string what)
  : m_status(status_code),
    m_what(what)
{

}
int StoreApiException::getStatus() const
{
    return m_status;
}
const char* StoreApiException::what() const noexcept
{
    return m_what.c_str();
}


template<class MODEL_T>
MODEL_T extractJsonModelBodyParam(const std::string& bodyContent)
{
    std::stringstream sstream(bodyContent);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream, pt);

    auto model = MODEL_T(pt);
    return model;
}

template<class MODEL_T>
std::vector<MODEL_T> extractJsonArrayBodyParam(const std::string& bodyContent)
{
    std::stringstream sstream(bodyContent);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream, pt);

    auto arrayRet = std::vector<MODEL_T>();
    for (const auto& child: pt) {
        arrayRet.emplace_back(MODEL_T(child.second));
    }
    return arrayRet;
}

template <class KEY_T, class VAL_T>
std::string convertMapResponse(const std::map<KEY_T, VAL_T>& map)
{
    boost::property_tree::ptree pt;
    for(const auto &kv: map) {
    pt.push_back(boost::property_tree::ptree::value_type(
        boost::lexical_cast<std::string>(kv.first),
        boost::property_tree::ptree(
        boost::lexical_cast<std::string>(kv.second))));
    }
    std::stringstream sstream;
    write_json(sstream, pt);
    std::string result = sstream.str();
    return result;
}

namespace StoreApiResources {
StoreOrderOrder_idResource::StoreOrderOrder_idResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/store/order/{order_id: .*}");
	this->set_method_handler("DELETE",
		std::bind(&StoreOrderOrder_idResource::handler_DELETE_internal, this,
			std::placeholders::_1));
	this->set_method_handler("GET",
		std::bind(&StoreOrderOrder_idResource::handler_GET_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> StoreOrderOrder_idResource::handleStoreApiException(const StoreApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> StoreOrderOrder_idResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> StoreOrderOrder_idResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void StoreOrderOrder_idResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void StoreOrderOrder_idResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void StoreOrderOrder_idResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void StoreOrderOrder_idResource::handler_DELETE_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // Getting the path params
    std::string orderId = request->get_path_parameter("order_id", "");
    
    int status_code = 500;
    std::string result = "";
    
    try {
        status_code =
            handler_DELETE(orderId);
    }
    catch(const StoreApiException& e) {
        std::tie(status_code, result) = handleStoreApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json"
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid ID supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 404) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Order not found";
    
        returnResponse(session, 404, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}

// x-extension
void StoreOrderOrder_idResource::handler_GET_internal(const std::shared_ptr<restbed::Session> session) {
    const auto request = session->get_request();
    // Getting the path params
    int64_t orderId = request->get_path_parameter("order_id", 0L);
    
    int status_code = 500;
    Order resultObject = Order{};
    std::string result = "";
    
    try {
        std::tie(status_code, resultObject) =
            handler_GET(orderId);
    }
    catch(const StoreApiException& e) {
        std::tie(status_code, result) = handleStoreApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/xml","application/json",
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 200) {
        responseHeaders.insert(std::make_pair("Content-Type", selectPreferredContentType(contentTypes)));
        if (!acceptTypes.empty()) {
            responseHeaders.insert(std::make_pair("Accept", acceptTypes));
        }
    
        result = resultObject.toJsonString();
        returnResponse(session, 200, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid ID supplied";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 404) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Order not found";
    
        returnResponse(session, 404, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}

int StoreOrderOrder_idResource::handler_DELETE(
        std::string & orderId)
{
    return handler_DELETE_func(orderId);
}

std::pair<int, Order> StoreOrderOrder_idResource::handler_GET(
    int64_t & orderId)
{
    return handler_GET_func(orderId);
}

std::string StoreOrderOrder_idResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string StoreOrderOrder_idResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
StoreInventoryResource::StoreInventoryResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/store/inventory");
	this->set_method_handler("GET",
		std::bind(&StoreInventoryResource::handler_GET_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> StoreInventoryResource::handleStoreApiException(const StoreApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> StoreInventoryResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> StoreInventoryResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void StoreInventoryResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void StoreInventoryResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void StoreInventoryResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void StoreInventoryResource::handler_GET_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    
    int status_code = 500;
    std::map<std::string, int32_t> resultObject = std::map<std::string, int32_t>();
    std::string result = "";
    
    try {
        std::tie(status_code, resultObject) =
            handler_GET();
    }
    catch(const StoreApiException& e) {
        std::tie(status_code, result) = handleStoreApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/json",
    };
    static const std::string acceptTypes{
    };
    
    if (status_code == 200) {
        responseHeaders.insert(std::make_pair("Content-Type", selectPreferredContentType(contentTypes)));
        if (!acceptTypes.empty()) {
            responseHeaders.insert(std::make_pair("Accept", acceptTypes));
        }
    
        result = convertMapResponse(resultObject);
        returnResponse(session, 200, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


std::pair<int, std::map<std::string, int32_t>> StoreInventoryResource::handler_GET(
        )
{
    return handler_GET_func();
}


std::string StoreInventoryResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string StoreInventoryResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}
StoreOrderResource::StoreOrderResource(const std::string& context /* = "/v2" */)
{
	this->set_path(context + "/store/order");
	this->set_method_handler("POST",
		std::bind(&StoreOrderResource::handler_POST_internal, this,
			std::placeholders::_1));
}

std::pair<int, std::string> StoreOrderResource::handleStoreApiException(const StoreApiException& e)
{
    return std::make_pair<int, std::string>(e.getStatus(), e.what());
}

std::pair<int, std::string> StoreOrderResource::handleStdException(const std::exception& e)
{
    return std::make_pair<int, std::string>(500, e.what());
}

std::pair<int, std::string> StoreOrderResource::handleUnspecifiedException()
{
    return std::make_pair<int, std::string>(500, "Unknown exception occurred");
}

void StoreOrderResource::setResponseHeader(const std::shared_ptr<restbed::Session>& session, const std::string& header)
{
    session->set_header(header, "");
}

void StoreOrderResource::returnResponse(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result, std::multimap<std::string, std::string>& responseHeaders)
{
    responseHeaders.insert(std::make_pair("Connection", "close"));
    session->close(status, result, responseHeaders);
}

void StoreOrderResource::defaultSessionClose(const std::shared_ptr<restbed::Session>& session, const int status, const std::string& result)
{
    session->close(status, result, { {"Connection", "close"} });
}

void StoreOrderResource::handler_POST_internal(const std::shared_ptr<restbed::Session> session)
{
    const auto request = session->get_request();
    // body params or form params here from the body content string
    std::string bodyContent = extractBodyContent(session);
    auto order = extractJsonModelBodyParam<Order>(bodyContent);
    
    int status_code = 500;
    Order resultObject = Order{};
    std::string result = "";
    
    try {
        std::tie(status_code, resultObject) =
            handler_POST(order);
    }
    catch(const StoreApiException& e) {
        std::tie(status_code, result) = handleStoreApiException(e);
    }
    catch(const std::exception& e) {
        std::tie(status_code, result) = handleStdException(e);
    }
    catch(...) {
        std::tie(status_code, result) = handleUnspecifiedException();
    }
    
    std::multimap< std::string, std::string > responseHeaders {};
    static const std::vector<std::string> contentTypes{
        "application/xml","application/json",
    };
    static const std::string acceptTypes{
        "application/json, "
    };
    
    if (status_code == 200) {
        responseHeaders.insert(std::make_pair("Content-Type", selectPreferredContentType(contentTypes)));
        if (!acceptTypes.empty()) {
            responseHeaders.insert(std::make_pair("Accept", acceptTypes));
        }
    
        result = resultObject.toJsonString();
        returnResponse(session, 200, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    if (status_code == 400) {
        responseHeaders.insert(std::make_pair("Content-Type", "text/plain"));
        result = "Invalid Order";
    
        returnResponse(session, 400, result.empty() ? "{}" : result, responseHeaders);
        return;
    }
    defaultSessionClose(session, status_code, result);
    
    
}


std::pair<int, Order> StoreOrderResource::handler_POST(
        Order & order)
{
    return handler_POST_func(order);
}


std::string StoreOrderResource::extractBodyContent(const std::shared_ptr<restbed::Session>& session) {
  const auto request = session->get_request();
  int content_length = request->get_header("Content-Length", 0);
  std::string bodyContent;
  session->fetch(content_length,
                 [&bodyContent](const std::shared_ptr<restbed::Session> session,
                                const restbed::Bytes &body) {
                   bodyContent = restbed::String::format(
                       "%.*s\n", (int)body.size(), body.data());
                 });
  return bodyContent;
}

std::string StoreOrderResource::extractFormParamsFromBody(const std::string& paramName, const std::string& body) {
    const auto uri = restbed::Uri("urlencoded?" + body, true);
    const auto params = uri.get_query_parameters();
    const auto result = params.find(paramName);
    if (result != params.cend()) {
        return result->second;
    }
    return "";
}

} /* namespace StoreApiResources */

StoreApi::StoreApi(std::shared_ptr<restbed::Service> const& restbedService)
: m_service(restbedService)
{
}

StoreApi::~StoreApi() {}

std::shared_ptr<StoreApiResources::StoreOrderOrder_idResource> StoreApi::getStoreOrderOrder_idResource() {
    if (!m_spStoreOrderOrder_idResource) {
        setResource(std::make_shared<StoreApiResources::StoreOrderOrder_idResource>());
    }
    return m_spStoreOrderOrder_idResource;
}
std::shared_ptr<StoreApiResources::StoreInventoryResource> StoreApi::getStoreInventoryResource() {
    if (!m_spStoreInventoryResource) {
        setResource(std::make_shared<StoreApiResources::StoreInventoryResource>());
    }
    return m_spStoreInventoryResource;
}
std::shared_ptr<StoreApiResources::StoreOrderResource> StoreApi::getStoreOrderResource() {
    if (!m_spStoreOrderResource) {
        setResource(std::make_shared<StoreApiResources::StoreOrderResource>());
    }
    return m_spStoreOrderResource;
}
void StoreApi::setResource(std::shared_ptr<StoreApiResources::StoreOrderOrder_idResource> resource) {
    m_spStoreOrderOrder_idResource = resource;
    m_service->publish(m_spStoreOrderOrder_idResource);
}
void StoreApi::setResource(std::shared_ptr<StoreApiResources::StoreInventoryResource> resource) {
    m_spStoreInventoryResource = resource;
    m_service->publish(m_spStoreInventoryResource);
}
void StoreApi::setResource(std::shared_ptr<StoreApiResources::StoreOrderResource> resource) {
    m_spStoreOrderResource = resource;
    m_service->publish(m_spStoreOrderResource);
}
void StoreApi::setStoreApiStoreOrderOrder_idResource(std::shared_ptr<StoreApiResources::StoreOrderOrder_idResource> spStoreOrderOrder_idResource) {
    m_spStoreOrderOrder_idResource = spStoreOrderOrder_idResource;
    m_service->publish(m_spStoreOrderOrder_idResource);
}
void StoreApi::setStoreApiStoreInventoryResource(std::shared_ptr<StoreApiResources::StoreInventoryResource> spStoreInventoryResource) {
    m_spStoreInventoryResource = spStoreInventoryResource;
    m_service->publish(m_spStoreInventoryResource);
}
void StoreApi::setStoreApiStoreOrderResource(std::shared_ptr<StoreApiResources::StoreOrderResource> spStoreOrderResource) {
    m_spStoreOrderResource = spStoreOrderResource;
    m_service->publish(m_spStoreOrderResource);
}


void StoreApi::publishDefaultResources() {
    if (!m_spStoreOrderOrder_idResource) {
        setResource(std::make_shared<StoreApiResources::StoreOrderOrder_idResource>());
    }
    if (!m_spStoreInventoryResource) {
        setResource(std::make_shared<StoreApiResources::StoreInventoryResource>());
    }
    if (!m_spStoreOrderResource) {
        setResource(std::make_shared<StoreApiResources::StoreOrderResource>());
    }
}

std::shared_ptr<restbed::Service> StoreApi::service() {
    return m_service;
}


}
}
}
}

