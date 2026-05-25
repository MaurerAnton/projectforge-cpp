/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <memory>
#include "projectforge-common/html/HtmlElement.hpp"
namespace org::projectforge::common::html {
class Html {
public:
    static std::shared_ptr<HtmlElement> div();
    static std::shared_ptr<HtmlElement> span();
    static std::shared_ptr<HtmlElement> p();
    static std::shared_ptr<HtmlElement> a(const std::string& href = "");
    static std::shared_ptr<HtmlElement> img(const std::string& src = "");
    static std::shared_ptr<HtmlElement> h1();
    static std::shared_ptr<HtmlElement> h2();
    static std::shared_ptr<HtmlElement> h3();
    static std::shared_ptr<HtmlElement> ul();
    static std::shared_ptr<HtmlElement> li();
    static std::shared_ptr<HtmlElement> table();
    static std::shared_ptr<HtmlElement> tr();
    static std::shared_ptr<HtmlElement> td();
    static std::shared_ptr<HtmlElement> th();
    static std::shared_ptr<HtmlElement> thead();
    static std::shared_ptr<HtmlElement> tbody();
    static std::shared_ptr<HtmlElement> form();
    static std::shared_ptr<HtmlElement> input(const std::string& type = "text");
    static std::shared_ptr<HtmlElement> button();
    static std::shared_ptr<HtmlElement> label();
    static std::shared_ptr<HtmlElement> select();
    static std::shared_ptr<HtmlElement> option();
    static std::shared_ptr<HtmlElement> textarea();
    static std::shared_ptr<HtmlElement> br();
    static std::shared_ptr<HtmlElement> hr();
    static std::shared_ptr<HtmlElement> script();
    static std::shared_ptr<HtmlElement> style();
    static std::shared_ptr<HtmlElement> link();
    static std::shared_ptr<HtmlElement> meta();
    static std::shared_ptr<HtmlElement> titleTag();
    static std::shared_ptr<HtmlElement> body();
    static std::shared_ptr<HtmlElement> head();
    static std::shared_ptr<HtmlElement> html();
    static std::shared_ptr<HtmlElement> nav();
    static std::shared_ptr<HtmlElement> section();
    static std::shared_ptr<HtmlElement> article();
    static std::shared_ptr<HtmlElement> footer();
    static std::shared_ptr<HtmlElement> header();
    static std::shared_ptr<HtmlElement> main();
};
}
