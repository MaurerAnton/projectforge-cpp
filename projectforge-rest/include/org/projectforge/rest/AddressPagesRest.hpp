// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/AddressDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <cstdint>

namespace org::projectforge::rest {

class AddressPagesRest : public RestController {
public:
    AddressPagesRest(std::shared_ptr<org::projectforge::business::address::AddressDao> addressDao);

    // GET /api/v1/addresses
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/addresses
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/addresses/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/addresses/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/addresses/search
    void search(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/favorites
    void favorites(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/birthdays
    void birthdays(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/by-organization
    void byOrganization(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/:id/vcard
    void exportVCard(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/addresses/import-vcard
    void importVCard(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/organizations — List distinct organizations
    void organizations(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/cities — List distinct cities
    void cities(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/addresses/:id/images
    void getImages(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/addresses/:id/images
    void addImage(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/addresses/:id/images/:imageId
    void removeImage(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t imageId);
    // POST /api/v1/addresses/:id/instant-messaging
    void getIMContacts(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/addresses/export
    void exportAddresses(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::address::AddressDao> addressDao_;
    json addressToApiJson(const org::projectforge::business::address::Address& addr) const;
    bool validateAddressData(const json& data, bool isUpdate, std::string& errorMsg) const;
};

} // namespace org::projectforge::rest
