/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>


#include "OAIApiRouter.h"
#include "OAIPetApiRequest.h"
#include "OAIStoreApiRequest.h"
#include "OAIUserApiRequest.h"


namespace OpenAPI {

OAIApiRouter::OAIApiRouter() {
    createApiHandlers();
}

OAIApiRouter::~OAIApiRouter(){
    
    delete OAIPetApiApiHandler;
    delete OAIStoreApiApiHandler;
    delete OAIUserApiApiHandler;
}

void OAIApiRouter::createApiHandlers() { 
    OAIPetApiApiHandler = new OAIPetApiHandler();
    OAIStoreApiApiHandler = new OAIStoreApiHandler();
    OAIUserApiApiHandler = new OAIUserApiHandler();
}

void OAIApiRouter::setUpRoutes() {
    
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/pet").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
            reqObj->addPetRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/pet/findByStatus").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
            reqObj->findPetsByStatusRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/pet/findByTags").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
            reqObj->findPetsByTagsRequest();
    });
    Routes.insert(QString("%1 %2").arg("PUT").arg("/v2/pet").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
            reqObj->updatePetRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/store/inventory").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIStoreApiRequest(socket, OAIStoreApiApiHandler);
            reqObj->getInventoryRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/store/order").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIStoreApiRequest(socket, OAIStoreApiApiHandler);
            reqObj->placeOrderRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
            reqObj->createUserRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user/createWithArray").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
            reqObj->createUsersWithArrayInputRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user/createWithList").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
            reqObj->createUsersWithListInputRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/user/login").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
            reqObj->loginUserRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/user/logout").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
            reqObj->logoutUserRequest();
    });
}

void OAIApiRouter::processRequest(QHttpEngine::Socket *socket){
    if( handleRequest(socket) ){
        return;
    }
    if( handleRequestAndExtractPathParam(socket) ){
        return;
    }
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    if(socket->isOpen()){
        socket->writeHeaders();
        socket->close();
    }
}

bool OAIApiRouter::handleRequest(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    if ( Routes.contains(reqPath) ) {
        Routes.value(reqPath).operator()(socket);
        return true;
    }
    return false;
}

bool OAIApiRouter::handleRequestAndExtractPathParam(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
                reqObj->deletePetRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
                reqObj->getPetByIdRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("POST").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
                reqObj->updatePetWithFormRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("POST").arg("/v2/pet/{petId}/uploadImage").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, OAIPetApiApiHandler);
                reqObj->uploadFileRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/store/order/{orderId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString orderId = match.captured(QString("orderId").toLower());
                auto reqObj = new OAIStoreApiRequest(socket, OAIStoreApiApiHandler);
                reqObj->deleteOrderRequest(orderId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/store/order/{orderId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString orderId = match.captured(QString("orderId").toLower());
                auto reqObj = new OAIStoreApiRequest(socket, OAIStoreApiApiHandler);
                reqObj->getOrderByIdRequest(orderId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
                reqObj->deleteUserRequest(username);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
                reqObj->getUserByNameRequest(username);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("PUT").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, OAIUserApiApiHandler);
                reqObj->updateUserRequest(username);
                return true;
            }
        }
    }
    return false;
}

}
