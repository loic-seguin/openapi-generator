# unit_test_api.MaximumApi

All URIs are relative to *https://someserver.com/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**post_maximum_validation_request_body**](MaximumApi.md#post_maximum_validation_request_body) | **post** /requestBody/postMaximumValidationRequestBody | 
[**post_maximum_validation_response_body_for_content_types**](MaximumApi.md#post_maximum_validation_response_body_for_content_types) | **post** /responseBody/postMaximumValidationResponseBodyForContentTypes | 
[**post_maximum_validation_with_unsigned_integer_request_body**](MaximumApi.md#post_maximum_validation_with_unsigned_integer_request_body) | **post** /requestBody/postMaximumValidationWithUnsignedIntegerRequestBody | 
[**post_maximum_validation_with_unsigned_integer_response_body_for_content_types**](MaximumApi.md#post_maximum_validation_with_unsigned_integer_response_body_for_content_types) | **post** /responseBody/postMaximumValidationWithUnsignedIntegerResponseBodyForContentTypes | 

# **post_maximum_validation_request_body**
> post_maximum_validation_request_body(body)



### Example

```python
import unit_test_api
from unit_test_api.apis.tags import maximum_api
from unit_test_api.model.maximum_validation import MaximumValidation
from pprint import pprint
# Defining the host is optional and defaults to https://someserver.com/v1
# See configuration.py for a list of all supported configuration parameters.
configuration = unit_test_api.Configuration(
    host = "https://someserver.com/v1"
)

# Enter a context with an instance of the API client
with unit_test_api.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = maximum_api.MaximumApi(api_client)

    # example passing only required values which don't have defaults set
    body = MaximumValidation(None)
    try:
        api_response = api_instance.post_maximum_validation_request_body(
            body=body,
        )
    except unit_test_api.ApiException as e:
        print("Exception when calling MaximumApi->post_maximum_validation_request_body: %s\n" % e)
```
### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
body | typing.Union[SchemaForRequestBodyApplicationJson] | required |
content_type | str | optional, default is 'application/json' | Selects the schema and serialization of the request body
stream | bool | default is False | if True then the response.content will be streamed and loaded from a file like object. When downloading a file, set this to True to force the code to deserialize the content to a FileSchema file
timeout | typing.Optional[typing.Union[int, typing.Tuple]] | default is None | the timeout used by the rest client
skip_deserialization | bool | default is False | when True, headers and body will be unset and an instance of api_client.ApiResponseWithoutDeserialization will be returned

### body

#### SchemaForRequestBodyApplicationJson
Type | Description  | Notes
------------- | ------------- | -------------
[**MaximumValidation**](MaximumValidation.md) |  | 


### Return Types, Responses

Code | Class | Description
------------- | ------------- | -------------
n/a | api_client.ApiResponseWithoutDeserialization | When skip_deserialization is True this response is returned
200 | ApiResponseFor200 | success

#### ApiResponseFor200
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
response | urllib3.HTTPResponse | Raw response |
body | Unset | body was not defined |
headers | Unset | headers were not defined |


void (empty response body)

### Authorization

No authorization required

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **post_maximum_validation_response_body_for_content_types**
> MaximumValidation post_maximum_validation_response_body_for_content_types()



### Example

```python
import unit_test_api
from unit_test_api.apis.tags import maximum_api
from unit_test_api.model.maximum_validation import MaximumValidation
from pprint import pprint
# Defining the host is optional and defaults to https://someserver.com/v1
# See configuration.py for a list of all supported configuration parameters.
configuration = unit_test_api.Configuration(
    host = "https://someserver.com/v1"
)

# Enter a context with an instance of the API client
with unit_test_api.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = maximum_api.MaximumApi(api_client)

    # example, this endpoint has no required or optional parameters
    try:
        api_response = api_instance.post_maximum_validation_response_body_for_content_types()
        pprint(api_response)
    except unit_test_api.ApiException as e:
        print("Exception when calling MaximumApi->post_maximum_validation_response_body_for_content_types: %s\n" % e)
```
### Parameters
This endpoint does not need any parameter.

### Return Types, Responses

Code | Class | Description
------------- | ------------- | -------------
n/a | api_client.ApiResponseWithoutDeserialization | When skip_deserialization is True this response is returned
200 | ApiResponseFor200 | success

#### ApiResponseFor200
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
response | urllib3.HTTPResponse | Raw response |
body | typing.Union[SchemaFor200ResponseBodyApplicationJson, ] |  |
headers | Unset | headers were not defined |

#### SchemaFor200ResponseBodyApplicationJson
Type | Description  | Notes
------------- | ------------- | -------------
[**MaximumValidation**](MaximumValidation.md) |  | 



[**MaximumValidation**](MaximumValidation.md)

### Authorization

No authorization required

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **post_maximum_validation_with_unsigned_integer_request_body**
> post_maximum_validation_with_unsigned_integer_request_body(body)



### Example

```python
import unit_test_api
from unit_test_api.apis.tags import maximum_api
from unit_test_api.model.maximum_validation_with_unsigned_integer import MaximumValidationWithUnsignedInteger
from pprint import pprint
# Defining the host is optional and defaults to https://someserver.com/v1
# See configuration.py for a list of all supported configuration parameters.
configuration = unit_test_api.Configuration(
    host = "https://someserver.com/v1"
)

# Enter a context with an instance of the API client
with unit_test_api.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = maximum_api.MaximumApi(api_client)

    # example passing only required values which don't have defaults set
    body = MaximumValidationWithUnsignedInteger(None)
    try:
        api_response = api_instance.post_maximum_validation_with_unsigned_integer_request_body(
            body=body,
        )
    except unit_test_api.ApiException as e:
        print("Exception when calling MaximumApi->post_maximum_validation_with_unsigned_integer_request_body: %s\n" % e)
```
### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
body | typing.Union[SchemaForRequestBodyApplicationJson] | required |
content_type | str | optional, default is 'application/json' | Selects the schema and serialization of the request body
stream | bool | default is False | if True then the response.content will be streamed and loaded from a file like object. When downloading a file, set this to True to force the code to deserialize the content to a FileSchema file
timeout | typing.Optional[typing.Union[int, typing.Tuple]] | default is None | the timeout used by the rest client
skip_deserialization | bool | default is False | when True, headers and body will be unset and an instance of api_client.ApiResponseWithoutDeserialization will be returned

### body

#### SchemaForRequestBodyApplicationJson
Type | Description  | Notes
------------- | ------------- | -------------
[**MaximumValidationWithUnsignedInteger**](MaximumValidationWithUnsignedInteger.md) |  | 


### Return Types, Responses

Code | Class | Description
------------- | ------------- | -------------
n/a | api_client.ApiResponseWithoutDeserialization | When skip_deserialization is True this response is returned
200 | ApiResponseFor200 | success

#### ApiResponseFor200
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
response | urllib3.HTTPResponse | Raw response |
body | Unset | body was not defined |
headers | Unset | headers were not defined |


void (empty response body)

### Authorization

No authorization required

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **post_maximum_validation_with_unsigned_integer_response_body_for_content_types**
> MaximumValidationWithUnsignedInteger post_maximum_validation_with_unsigned_integer_response_body_for_content_types()



### Example

```python
import unit_test_api
from unit_test_api.apis.tags import maximum_api
from unit_test_api.model.maximum_validation_with_unsigned_integer import MaximumValidationWithUnsignedInteger
from pprint import pprint
# Defining the host is optional and defaults to https://someserver.com/v1
# See configuration.py for a list of all supported configuration parameters.
configuration = unit_test_api.Configuration(
    host = "https://someserver.com/v1"
)

# Enter a context with an instance of the API client
with unit_test_api.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = maximum_api.MaximumApi(api_client)

    # example, this endpoint has no required or optional parameters
    try:
        api_response = api_instance.post_maximum_validation_with_unsigned_integer_response_body_for_content_types()
        pprint(api_response)
    except unit_test_api.ApiException as e:
        print("Exception when calling MaximumApi->post_maximum_validation_with_unsigned_integer_response_body_for_content_types: %s\n" % e)
```
### Parameters
This endpoint does not need any parameter.

### Return Types, Responses

Code | Class | Description
------------- | ------------- | -------------
n/a | api_client.ApiResponseWithoutDeserialization | When skip_deserialization is True this response is returned
200 | ApiResponseFor200 | success

#### ApiResponseFor200
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
response | urllib3.HTTPResponse | Raw response |
body | typing.Union[SchemaFor200ResponseBodyApplicationJson, ] |  |
headers | Unset | headers were not defined |

#### SchemaFor200ResponseBodyApplicationJson
Type | Description  | Notes
------------- | ------------- | -------------
[**MaximumValidationWithUnsignedInteger**](MaximumValidationWithUnsignedInteger.md) |  | 



[**MaximumValidationWithUnsignedInteger**](MaximumValidationWithUnsignedInteger.md)

### Authorization

No authorization required

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)
