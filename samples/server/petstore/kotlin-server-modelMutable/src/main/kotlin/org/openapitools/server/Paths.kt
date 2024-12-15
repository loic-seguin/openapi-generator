/**
* OpenAPI Petstore
* This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
*
* The version of the OpenAPI document: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
package org.openapitools.server

import io.ktor.resources.*
import kotlinx.serialization.*
import org.openapitools.server.models.*

object Paths {
    /**
     * Add a new pet to the store
     * 
     * @param body Pet object that needs to be added to the store 
     */
    @Resource("/pet") class addPet()

    /**
     * Deletes a pet
     * 
     * @param petId Pet id to delete 
     * @param apiKey  (optional)
     */
    @Resource("/pet/{petId}") class deletePet(val petId: kotlin.Long)

    /**
     * Finds Pets by status
     * Multiple status values can be provided with comma separated strings
     * @param status Status values that need to be considered for filter 
     */
    @Resource("/pet/findByStatus") class findPetsByStatus(val status: kotlin.collections.MutableList<kotlin.String>)

    /**
     * Finds Pets by tags
     * Multiple tags can be provided with comma separated strings. Use tag1, tag2, tag3 for testing.
     * @param tags Tags to filter by 
     */
    @Resource("/pet/findByTags") class findPetsByTags(val tags: kotlin.collections.MutableList<kotlin.String>)

    /**
     * Find pet by ID
     * Returns a single pet
     * @param petId ID of pet to return 
     */
    @Resource("/pet/{petId}") class getPetById(val petId: kotlin.Long)

    /**
     * Update an existing pet
     * 
     * @param body Pet object that needs to be added to the store 
     */
    @Resource("/pet") class updatePet()

    /**
     * Updates a pet in the store with form data
     * 
     * @param petId ID of pet that needs to be updated 
     * @param name Updated name of the pet (optional)
     * @param status Updated status of the pet (optional)
     */
    @Resource("/pet/{petId}") class updatePetWithForm(val petId: kotlin.Long)

    /**
     * uploads an image
     * 
     * @param petId ID of pet to update 
     * @param additionalMetadata Additional data to pass to server (optional)
     * @param file file to upload (optional)
     */
    @Resource("/pet/{petId}/uploadImage") class uploadFile(val petId: kotlin.Long)

    /**
     * Delete purchase order by ID
     * For valid response try integer IDs with value &lt; 1000. Anything above 1000 or nonintegers will generate API errors
     * @param orderId ID of the order that needs to be deleted 
     */
    @Resource("/store/order/{orderId}") class deleteOrder(val orderId: kotlin.String)

    /**
     * Returns pet inventories by status
     * Returns a map of status codes to quantities
     */
    @Resource("/store/inventory") class getInventory

    /**
     * Find purchase order by ID
     * For valid response try integer IDs with value &lt;&#x3D; 5 or &gt; 10. Other values will generate exceptions
     * @param orderId ID of pet that needs to be fetched 
     */
    @Resource("/store/order/{orderId}") class getOrderById(val orderId: kotlin.Long)

    /**
     * Place an order for a pet
     * 
     * @param body order placed for purchasing the pet 
     */
    @Resource("/store/order") class placeOrder()

    /**
     * Create user
     * This can only be done by the logged in user.
     * @param body Created user object 
     */
    @Resource("/user") class createUser()

    /**
     * Creates list of users with given input array
     * 
     * @param body List of user object 
     */
    @Resource("/user/createWithArray") class createUsersWithArrayInput()

    /**
     * Creates list of users with given input array
     * 
     * @param body List of user object 
     */
    @Resource("/user/createWithList") class createUsersWithListInput()

    /**
     * Delete user
     * This can only be done by the logged in user.
     * @param username The name that needs to be deleted 
     */
    @Resource("/user/{username}") class deleteUser(val username: kotlin.String)

    /**
     * Get user by user name
     * 
     * @param username The name that needs to be fetched. Use user1 for testing. 
     */
    @Resource("/user/{username}") class getUserByName(val username: kotlin.String)

    /**
     * Logs user into the system
     * 
     * @param username The user name for login 
     * @param password The password for login in clear text 
     */
    @Resource("/user/login") class loginUser(val username: kotlin.String, val password: kotlin.String)

    /**
     * Logs out current logged in user session
     * 
     */
    @Resource("/user/logout") class logoutUser

    /**
     * Updated user
     * This can only be done by the logged in user.
     * @param username name that need to be deleted 
     * @param body Updated user object 
     */
    @Resource("/user/{username}") class updateUser(val username: kotlin.String)

}
