/*
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

package org.openapitools.model;

import java.util.Objects;
import java.util.Arrays;
import org.openapitools.model.Animal;
import com.fasterxml.jackson.annotation.*;

import javax.validation.constraints.*;
import javax.validation.Valid;
import io.micronaut.core.annotation.*;
import javax.annotation.Generated;

/**
 * Cat
 */
@JsonPropertyOrder({
  Cat.JSON_PROPERTY_DECLAWED
})
@JsonTypeName("Cat")
@Generated(value="org.openapitools.codegen.languages.JavaMicronautClientCodegen", comments = "Generator version: 7.11.0-SNAPSHOT")
@Introspected
public class Cat extends Animal {
    public static final String JSON_PROPERTY_DECLAWED = "declawed";
    private Boolean declawed;

    public Cat() {
        super();
    }
    public Cat declawed(Boolean declawed) {
        this.declawed = declawed;
        return this;
    }

    /**
     * Get declawed
     * @return declawed
     */
    @Nullable
    @JsonProperty(JSON_PROPERTY_DECLAWED)
    @JsonInclude(value = JsonInclude.Include.USE_DEFAULTS)
    public Boolean getDeclawed() {
        return declawed;
    }

    @JsonProperty(JSON_PROPERTY_DECLAWED)
    @JsonInclude(value = JsonInclude.Include.USE_DEFAULTS)
    public void setDeclawed(Boolean declawed) {
        this.declawed = declawed;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Cat cat = (Cat) o;
        return Objects.equals(this.declawed, cat.declawed) &&
            super.equals(o);
    }

    @Override
    public int hashCode() {
        return Objects.hash(declawed, super.hashCode());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("class Cat {\n");
        sb.append("    ").append(toIndentedString(super.toString())).append("\n");
        sb.append("    declawed: ").append(toIndentedString(declawed)).append("\n");
        sb.append("}");
        return sb.toString();
    }

    /**
     * Convert the given object to string with each line indented by 4 spaces
     * (except the first line).
     */
    private String toIndentedString(Object o) {
        if (o == null) {
            return "null";
        }
        return o.toString().replace("\n", "\n    ");
    }

    @Override
    public <T> T accept(Animal.Visitor<T> visitor) {
        return visitor.visitCat(this);
    }
}

