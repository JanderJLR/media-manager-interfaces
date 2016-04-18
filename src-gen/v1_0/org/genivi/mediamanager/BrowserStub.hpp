/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.3.v201507280808.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef ORG_GENIVI_MEDIAMANAGER_Browser_STUB_HPP_
#define ORG_GENIVI_MEDIAMANAGER_Browser_STUB_HPP_

#include <functional>



#include <v1_0/org/genivi/mediamanager/BrowserTypes.hpp>
#include <v1_0/org/genivi/mediamanager/MediaTypes.hpp>

#include <v1_0/org/genivi/mediamanager/Browser.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <string>
#include <vector>

#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1_0 {
namespace org {
namespace genivi {
namespace mediamanager {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service Browser. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class BrowserStubAdapter
    : virtual public CommonAPI::StubAdapter, 
      public Browser {
 public:



    virtual void deactivateManagedInstances() = 0;
protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for Browser.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class BrowserStubRemoteEvent
{
public:
    virtual ~BrowserStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service Browser to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class BrowserStub
    : public virtual CommonAPI::Stub<BrowserStubAdapter, BrowserStubRemoteEvent>
{
public:
    typedef std::function<void (std::vector<std::string> _identifiers, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>discoverMediaManagersReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listContainersReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listContainersExReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listItemsReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listItemsExReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listChildrenReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listChildrenExReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>searchObjectsReply_t;
    typedef std::function<void (::v1_0::org::genivi::mediamanager::MediaTypes::ResultMapList _m, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>searchObjectsExReply_t;
    typedef std::function<void (std::string _indexes, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>listIndexesReply_t;
    typedef std::function<void (std::string _pathIdentifier, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>createContainerReply_t;
    typedef std::function<void (std::string _pathIdentifier, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError _e)>createReferenceReply_t;

    virtual ~BrowserStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;


    /**
     * description: Return a list of all media manager identifiers. These are
             used to
     *   indicate which media manager we should interact with.
             returns: A list
     *   of all media managers found
     */
    /// This is the method that will be called on remote calls on the method discoverMediaManagers.
    virtual void discoverMediaManagers(const std::shared_ptr<CommonAPI::ClientId> _client, discoverMediaManagersReply_t _reply) = 0;
    /**
     * description: List all containers below the given path.
             returns: ResultMapList of
     *   all containers with the given path as parent.
             	   	  See
     *   MediaTypes.fidl for a list of allowed keys.
             errors: NO_CONNECTION if
     *   no connection can be established to underlying
                     browsing
     *   engine
                     BAD_PATH if path parameter is invalid
     * param: path The path to search for containers. The format of the path
                   
     *   depends on the underlying browsing backend
     * param: offset: The offset to use for indexing the results list
     * param: count: The number of results to return, starting from offset
     * param: filter: Array of keys to include in resulting ResultMapList
     */
    /// This is the method that will be called on remote calls on the method listContainers.
    virtual void listContainers(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listContainersReply_t _reply) = 0;
    /**
     * description: Extends ListContainers with sorting capabilities
     * param: sortKey Key to sort ResultMapList on
     */
    /// This is the method that will be called on remote calls on the method listContainersEx.
    virtual void listContainersEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listContainersExReply_t _reply) = 0;
    /**
     * description: List all items in the given container
             returns: A ResultMapList of all
     *   items with the given container as parent.
             		  See MediaTypes.fidl for
     *   a list of allowed keys.
             errors: NO_CONNECTION if no connection can be
     *   established to underlying
                     browsing engine
                    
     *   BAD_PATH if path parameter is invalid
     * param: path The path of the container to search for items.
                    The format
     *   of the path depends on the underlying browsing
                    backend
     * param: offset: The offset to use for indexing the results list
     * param: count: The number of results to return, starting from offset
     * param: filter: Array of keys to include in resulting ResultMapList
     */
    /// This is the method that will be called on remote calls on the method listItems.
    virtual void listItems(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listItemsReply_t _reply) = 0;
    /**
     * description: Extends ListItems with sorting capabilities
     * param: sortKey Key to sort ResultMapList
     */
    /// This is the method that will be called on remote calls on the method listItemsEx.
    virtual void listItemsEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listItemsExReply_t _reply) = 0;
    /**
     * description: List all children in the given container
             returns: A ResultMapList of
     *   all children with the given container as parent.
             		  See
     *   MediaTypes.fidl for a list of allowed keys.
             errors: NO_CONNECTION if
     *   no connection can be established to underlying
                      browsing
     *   engine
                      BAD_PATH if path parameter is invalid
     * param: path The path of the container to search for children.
                    The
     *   format of the path depends on the underlying browsing
                    backend
     * param: offset: The offset to use for indexing the results list
     * param: count: The number of results to return, starting from offset
     * param: filter: Array of keys to include in resulting ResultMapList
     */
    /// This is the method that will be called on remote calls on the method listChildren.
    virtual void listChildren(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listChildrenReply_t _reply) = 0;
    /**
     * description: Extends ListChildren with sorting capabilities
     * param: sortKey Key to sort ResultMapList on
     */
    /// This is the method that will be called on remote calls on the method listChildrenEx.
    virtual void listChildrenEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listChildrenExReply_t _reply) = 0;
    /**
     * description: Search for children in the given container
             returns: A ResultMapList of
     *   all children matching the search criteria with
                       the given
     *   container as parent.See MediaTypes.fidl for a list of
                      
     *   allowed keys.
             errors: NO_CONNECTION if no connection can be
     *   established to underlying
                     browsing engine
                    
     *   BAD_PATH if path parameter is invalid
     * param: path The path of the container to search for children.
                    The
     *   format of the path depends on the underlying browsing
                    backend
     * param: query Search query to match children against. The format of the
                   
     *   query depends on the underlying browsing backend
     * param: offset: The offset to use for indexing the results list
     * param: count: The number of results to return, starting from offset
     * param: filter: Array of keys to include in resulting ResultMapList
     */
    /// This is the method that will be called on remote calls on the method searchObjects.
    virtual void searchObjects(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _query, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, searchObjectsReply_t _reply) = 0;
    /**
     * description: Extends SearchObjects with sorting capabilities
     * param: sortKey Key to sort ResultMapList on
     */
    /// This is the method that will be called on remote calls on the method searchObjectsEx.
    virtual void searchObjectsEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _query, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, searchObjectsExReply_t _reply) = 0;
    /**
     * description: Get a list of all initial letters and their index in the
                         
     *   given container
             returns: A list of tuples of initial letters and
     *   their first
                       observed position when sorting according to
     *   sortKey
             errors: NO_CONNECTION if no connection can be established to
     *   underlying
                     browsing engine
                     BAD_PATH if path
     *   parameter is invalid
     * param: container: Container to build index list for
     * param: count: How many (unsorted) items should be traversed to build
                     
     *          index
     * param: filter: List of initial letters to include
     * param: sortKey: Key to sort on when building index list
     */
    /// This is the method that will be called on remote calls on the method listIndexes.
    virtual void listIndexes(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _container, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listIndexesReply_t _reply) = 0;
    /**
     * description: Create a new empty container with path used as root
             returns: Path
     *   identifier for the newly created container
             errors: NO_CONNECTION if
     *   no connection can be established to underlying
                      browsing
     *   engine
                      BAD_PATH if path parameter is invalid
     * param: path: Path to place the newly created container in
     * param: displayName: Display name for the new container
     * param: childTypes: Array of allowed types on children in new container
     */
    /// This is the method that will be called on remote calls on the method createContainer.
    virtual void createContainer(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _displayName, std::vector<std::string> _childTypes, createContainerReply_t _reply) = 0;
    /**
     * description: Place a reference in a container, pointing to an object
             returns: Path
     *   identifier for the container containing the reference
             errors:
     *   NO_CONNECTION if no connection can be established to underlying
                  
     *      browsing engine
                      BAD_PATH if path parameter is invalid
     * param: path: Path to place the newly created container in
     * param: objectPath: Path to object to create reference to
     */
    /// This is the method that will be called on remote calls on the method createReference.
    virtual void createReference(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _objectPath, createReferenceReply_t _reply) = 0;

    using CommonAPI::Stub<BrowserStubAdapter, BrowserStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<BrowserStubAdapter, BrowserStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<BrowserStubAdapter, BrowserStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef BrowserStubRemoteEvent RemoteEventType;
    typedef Browser StubInterface;
};

} // namespace mediamanager
} // namespace genivi
} // namespace org
} // namespace v1_0

#endif // ORG_GENIVI_MEDIAMANAGER_Browser_STUB_HPP_
