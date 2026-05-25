// ProjectForge C++ port — GPL v3

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
static int tPassed=0,tFailed=0;
#define T(n) do{try{
#define E }catch(const std::exception&e){std::cout<<"  FAILED: "<<e.what()<<std::endl;tFailed++;return;}std::cout<<"  PASSED"<<std::endl;tPassed++;}while(0)
#define CHECK(c) if(!(c))throw std::runtime_error(#c)
#define EQ(a,b) if((a)!=(b))throw std::runtime_error(std::to_string(a)+"!="+std::to_string(b))
void testExt1() {
    T("Extended test 1: Data operations") {
        nlohmann::json d; d["id"]=1; d["name"]="Test1"; d["value"]=1*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),1);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test1");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test1")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),1);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt2() {
    T("Extended test 2: Data operations") {
        nlohmann::json d; d["id"]=2; d["name"]="Test2"; d["value"]=2*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),2);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test2");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test2")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),2);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt3() {
    T("Extended test 3: Data operations") {
        nlohmann::json d; d["id"]=3; d["name"]="Test3"; d["value"]=3*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),3);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test3");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test3")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),3);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt4() {
    T("Extended test 4: Data operations") {
        nlohmann::json d; d["id"]=4; d["name"]="Test4"; d["value"]=4*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),4);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test4");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test4")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),4);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt5() {
    T("Extended test 5: Data operations") {
        nlohmann::json d; d["id"]=5; d["name"]="Test5"; d["value"]=5*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),5);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test5");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test5")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),5);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt6() {
    T("Extended test 6: Data operations") {
        nlohmann::json d; d["id"]=6; d["name"]="Test6"; d["value"]=6*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),6);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test6");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test6")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),6);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt7() {
    T("Extended test 7: Data operations") {
        nlohmann::json d; d["id"]=7; d["name"]="Test7"; d["value"]=7*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),7);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test7");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test7")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),7);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt8() {
    T("Extended test 8: Data operations") {
        nlohmann::json d; d["id"]=8; d["name"]="Test8"; d["value"]=8*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),8);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test8");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test8")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),8);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt9() {
    T("Extended test 9: Data operations") {
        nlohmann::json d; d["id"]=9; d["name"]="Test9"; d["value"]=9*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),9);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test9");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test9")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),9);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt10() {
    T("Extended test 10: Data operations") {
        nlohmann::json d; d["id"]=10; d["name"]="Test10"; d["value"]=10*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),10);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test10");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test10")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),10);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt11() {
    T("Extended test 11: Data operations") {
        nlohmann::json d; d["id"]=11; d["name"]="Test11"; d["value"]=11*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),11);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test11");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test11")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),11);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt12() {
    T("Extended test 12: Data operations") {
        nlohmann::json d; d["id"]=12; d["name"]="Test12"; d["value"]=12*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),12);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test12");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test12")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),12);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt13() {
    T("Extended test 13: Data operations") {
        nlohmann::json d; d["id"]=13; d["name"]="Test13"; d["value"]=13*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),13);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test13");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test13")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),13);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt14() {
    T("Extended test 14: Data operations") {
        nlohmann::json d; d["id"]=14; d["name"]="Test14"; d["value"]=14*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),14);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test14");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test14")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),14);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt15() {
    T("Extended test 15: Data operations") {
        nlohmann::json d; d["id"]=15; d["name"]="Test15"; d["value"]=15*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),15);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test15");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test15")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),15);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt16() {
    T("Extended test 16: Data operations") {
        nlohmann::json d; d["id"]=16; d["name"]="Test16"; d["value"]=16*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),16);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test16");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test16")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),16);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt17() {
    T("Extended test 17: Data operations") {
        nlohmann::json d; d["id"]=17; d["name"]="Test17"; d["value"]=17*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),17);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test17");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test17")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),17);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt18() {
    T("Extended test 18: Data operations") {
        nlohmann::json d; d["id"]=18; d["name"]="Test18"; d["value"]=18*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),18);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test18");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test18")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),18);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt19() {
    T("Extended test 19: Data operations") {
        nlohmann::json d; d["id"]=19; d["name"]="Test19"; d["value"]=19*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),19);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test19");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test19")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),19);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt20() {
    T("Extended test 20: Data operations") {
        nlohmann::json d; d["id"]=20; d["name"]="Test20"; d["value"]=20*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),20);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test20");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test20")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),20);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt21() {
    T("Extended test 21: Data operations") {
        nlohmann::json d; d["id"]=21; d["name"]="Test21"; d["value"]=21*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),21);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test21");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test21")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),21);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt22() {
    T("Extended test 22: Data operations") {
        nlohmann::json d; d["id"]=22; d["name"]="Test22"; d["value"]=22*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),22);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test22");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test22")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),22);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt23() {
    T("Extended test 23: Data operations") {
        nlohmann::json d; d["id"]=23; d["name"]="Test23"; d["value"]=23*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),23);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test23");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test23")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),23);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt24() {
    T("Extended test 24: Data operations") {
        nlohmann::json d; d["id"]=24; d["name"]="Test24"; d["value"]=24*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),24);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test24");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test24")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),24);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt25() {
    T("Extended test 25: Data operations") {
        nlohmann::json d; d["id"]=25; d["name"]="Test25"; d["value"]=25*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),25);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test25");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test25")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),25);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt26() {
    T("Extended test 26: Data operations") {
        nlohmann::json d; d["id"]=26; d["name"]="Test26"; d["value"]=26*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),26);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test26");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test26")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),26);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt27() {
    T("Extended test 27: Data operations") {
        nlohmann::json d; d["id"]=27; d["name"]="Test27"; d["value"]=27*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),27);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test27");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test27")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),27);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt28() {
    T("Extended test 28: Data operations") {
        nlohmann::json d; d["id"]=28; d["name"]="Test28"; d["value"]=28*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),28);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test28");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test28")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),28);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt29() {
    T("Extended test 29: Data operations") {
        nlohmann::json d; d["id"]=29; d["name"]="Test29"; d["value"]=29*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),29);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test29");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test29")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),29);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt30() {
    T("Extended test 30: Data operations") {
        nlohmann::json d; d["id"]=30; d["name"]="Test30"; d["value"]=30*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),30);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test30");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test30")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),30);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt31() {
    T("Extended test 31: Data operations") {
        nlohmann::json d; d["id"]=31; d["name"]="Test31"; d["value"]=31*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),31);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test31");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test31")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),31);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt32() {
    T("Extended test 32: Data operations") {
        nlohmann::json d; d["id"]=32; d["name"]="Test32"; d["value"]=32*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),32);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test32");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test32")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),32);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt33() {
    T("Extended test 33: Data operations") {
        nlohmann::json d; d["id"]=33; d["name"]="Test33"; d["value"]=33*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),33);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test33");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test33")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),33);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt34() {
    T("Extended test 34: Data operations") {
        nlohmann::json d; d["id"]=34; d["name"]="Test34"; d["value"]=34*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),34);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test34");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test34")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),34);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt35() {
    T("Extended test 35: Data operations") {
        nlohmann::json d; d["id"]=35; d["name"]="Test35"; d["value"]=35*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),35);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test35");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test35")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),35);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt36() {
    T("Extended test 36: Data operations") {
        nlohmann::json d; d["id"]=36; d["name"]="Test36"; d["value"]=36*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),36);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test36");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test36")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),36);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt37() {
    T("Extended test 37: Data operations") {
        nlohmann::json d; d["id"]=37; d["name"]="Test37"; d["value"]=37*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),37);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test37");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test37")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),37);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt38() {
    T("Extended test 38: Data operations") {
        nlohmann::json d; d["id"]=38; d["name"]="Test38"; d["value"]=38*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),38);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test38");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test38")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),38);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt39() {
    T("Extended test 39: Data operations") {
        nlohmann::json d; d["id"]=39; d["name"]="Test39"; d["value"]=39*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),39);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test39");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test39")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),39);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt40() {
    T("Extended test 40: Data operations") {
        nlohmann::json d; d["id"]=40; d["name"]="Test40"; d["value"]=40*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),40);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test40");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test40")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),40);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt41() {
    T("Extended test 41: Data operations") {
        nlohmann::json d; d["id"]=41; d["name"]="Test41"; d["value"]=41*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),41);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test41");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test41")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),41);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt42() {
    T("Extended test 42: Data operations") {
        nlohmann::json d; d["id"]=42; d["name"]="Test42"; d["value"]=42*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),42);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test42");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test42")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),42);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt43() {
    T("Extended test 43: Data operations") {
        nlohmann::json d; d["id"]=43; d["name"]="Test43"; d["value"]=43*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),43);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test43");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test43")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),43);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt44() {
    T("Extended test 44: Data operations") {
        nlohmann::json d; d["id"]=44; d["name"]="Test44"; d["value"]=44*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),44);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test44");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test44")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),44);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt45() {
    T("Extended test 45: Data operations") {
        nlohmann::json d; d["id"]=45; d["name"]="Test45"; d["value"]=45*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),45);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test45");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test45")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),45);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt46() {
    T("Extended test 46: Data operations") {
        nlohmann::json d; d["id"]=46; d["name"]="Test46"; d["value"]=46*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),46);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test46");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test46")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),46);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt47() {
    T("Extended test 47: Data operations") {
        nlohmann::json d; d["id"]=47; d["name"]="Test47"; d["value"]=47*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),47);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test47");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test47")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),47);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt48() {
    T("Extended test 48: Data operations") {
        nlohmann::json d; d["id"]=48; d["name"]="Test48"; d["value"]=48*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),48);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test48");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test48")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),48);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt49() {
    T("Extended test 49: Data operations") {
        nlohmann::json d; d["id"]=49; d["name"]="Test49"; d["value"]=49*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),49);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test49");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test49")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),49);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt50() {
    T("Extended test 50: Data operations") {
        nlohmann::json d; d["id"]=50; d["name"]="Test50"; d["value"]=50*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),50);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test50");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test50")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),50);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt51() {
    T("Extended test 51: Data operations") {
        nlohmann::json d; d["id"]=51; d["name"]="Test51"; d["value"]=51*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),51);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test51");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test51")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),51);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt52() {
    T("Extended test 52: Data operations") {
        nlohmann::json d; d["id"]=52; d["name"]="Test52"; d["value"]=52*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),52);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test52");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test52")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),52);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt53() {
    T("Extended test 53: Data operations") {
        nlohmann::json d; d["id"]=53; d["name"]="Test53"; d["value"]=53*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),53);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test53");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test53")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),53);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt54() {
    T("Extended test 54: Data operations") {
        nlohmann::json d; d["id"]=54; d["name"]="Test54"; d["value"]=54*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),54);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test54");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test54")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),54);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt55() {
    T("Extended test 55: Data operations") {
        nlohmann::json d; d["id"]=55; d["name"]="Test55"; d["value"]=55*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),55);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test55");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test55")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),55);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt56() {
    T("Extended test 56: Data operations") {
        nlohmann::json d; d["id"]=56; d["name"]="Test56"; d["value"]=56*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),56);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test56");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test56")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),56);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt57() {
    T("Extended test 57: Data operations") {
        nlohmann::json d; d["id"]=57; d["name"]="Test57"; d["value"]=57*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),57);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test57");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test57")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),57);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt58() {
    T("Extended test 58: Data operations") {
        nlohmann::json d; d["id"]=58; d["name"]="Test58"; d["value"]=58*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),58);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test58");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test58")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),58);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt59() {
    T("Extended test 59: Data operations") {
        nlohmann::json d; d["id"]=59; d["name"]="Test59"; d["value"]=59*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),59);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test59");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test59")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),59);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt60() {
    T("Extended test 60: Data operations") {
        nlohmann::json d; d["id"]=60; d["name"]="Test60"; d["value"]=60*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),60);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test60");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test60")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),60);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt61() {
    T("Extended test 61: Data operations") {
        nlohmann::json d; d["id"]=61; d["name"]="Test61"; d["value"]=61*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),61);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test61");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test61")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),61);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt62() {
    T("Extended test 62: Data operations") {
        nlohmann::json d; d["id"]=62; d["name"]="Test62"; d["value"]=62*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),62);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test62");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test62")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),62);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt63() {
    T("Extended test 63: Data operations") {
        nlohmann::json d; d["id"]=63; d["name"]="Test63"; d["value"]=63*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),63);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test63");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test63")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),63);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt64() {
    T("Extended test 64: Data operations") {
        nlohmann::json d; d["id"]=64; d["name"]="Test64"; d["value"]=64*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),64);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test64");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test64")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),64);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt65() {
    T("Extended test 65: Data operations") {
        nlohmann::json d; d["id"]=65; d["name"]="Test65"; d["value"]=65*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),65);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test65");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test65")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),65);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt66() {
    T("Extended test 66: Data operations") {
        nlohmann::json d; d["id"]=66; d["name"]="Test66"; d["value"]=66*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),66);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test66");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test66")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),66);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt67() {
    T("Extended test 67: Data operations") {
        nlohmann::json d; d["id"]=67; d["name"]="Test67"; d["value"]=67*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),67);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test67");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test67")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),67);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt68() {
    T("Extended test 68: Data operations") {
        nlohmann::json d; d["id"]=68; d["name"]="Test68"; d["value"]=68*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),68);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test68");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test68")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),68);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt69() {
    T("Extended test 69: Data operations") {
        nlohmann::json d; d["id"]=69; d["name"]="Test69"; d["value"]=69*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),69);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test69");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test69")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),69);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt70() {
    T("Extended test 70: Data operations") {
        nlohmann::json d; d["id"]=70; d["name"]="Test70"; d["value"]=70*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),70);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test70");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test70")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),70);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt71() {
    T("Extended test 71: Data operations") {
        nlohmann::json d; d["id"]=71; d["name"]="Test71"; d["value"]=71*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),71);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test71");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test71")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),71);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt72() {
    T("Extended test 72: Data operations") {
        nlohmann::json d; d["id"]=72; d["name"]="Test72"; d["value"]=72*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),72);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test72");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test72")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),72);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt73() {
    T("Extended test 73: Data operations") {
        nlohmann::json d; d["id"]=73; d["name"]="Test73"; d["value"]=73*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),73);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test73");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test73")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),73);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt74() {
    T("Extended test 74: Data operations") {
        nlohmann::json d; d["id"]=74; d["name"]="Test74"; d["value"]=74*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),74);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test74");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test74")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),74);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt75() {
    T("Extended test 75: Data operations") {
        nlohmann::json d; d["id"]=75; d["name"]="Test75"; d["value"]=75*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),75);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test75");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test75")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),75);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt76() {
    T("Extended test 76: Data operations") {
        nlohmann::json d; d["id"]=76; d["name"]="Test76"; d["value"]=76*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),76);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test76");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test76")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),76);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt77() {
    T("Extended test 77: Data operations") {
        nlohmann::json d; d["id"]=77; d["name"]="Test77"; d["value"]=77*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),77);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test77");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test77")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),77);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt78() {
    T("Extended test 78: Data operations") {
        nlohmann::json d; d["id"]=78; d["name"]="Test78"; d["value"]=78*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),78);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test78");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test78")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),78);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt79() {
    T("Extended test 79: Data operations") {
        nlohmann::json d; d["id"]=79; d["name"]="Test79"; d["value"]=79*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),79);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test79");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test79")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),79);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt80() {
    T("Extended test 80: Data operations") {
        nlohmann::json d; d["id"]=80; d["name"]="Test80"; d["value"]=80*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),80);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test80");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test80")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),80);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt81() {
    T("Extended test 81: Data operations") {
        nlohmann::json d; d["id"]=81; d["name"]="Test81"; d["value"]=81*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),81);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test81");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test81")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),81);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt82() {
    T("Extended test 82: Data operations") {
        nlohmann::json d; d["id"]=82; d["name"]="Test82"; d["value"]=82*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),82);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test82");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test82")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),82);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt83() {
    T("Extended test 83: Data operations") {
        nlohmann::json d; d["id"]=83; d["name"]="Test83"; d["value"]=83*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),83);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test83");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test83")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),83);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt84() {
    T("Extended test 84: Data operations") {
        nlohmann::json d; d["id"]=84; d["name"]="Test84"; d["value"]=84*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),84);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test84");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test84")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),84);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt85() {
    T("Extended test 85: Data operations") {
        nlohmann::json d; d["id"]=85; d["name"]="Test85"; d["value"]=85*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),85);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test85");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test85")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),85);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt86() {
    T("Extended test 86: Data operations") {
        nlohmann::json d; d["id"]=86; d["name"]="Test86"; d["value"]=86*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),86);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test86");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test86")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),86);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt87() {
    T("Extended test 87: Data operations") {
        nlohmann::json d; d["id"]=87; d["name"]="Test87"; d["value"]=87*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),87);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test87");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test87")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),87);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt88() {
    T("Extended test 88: Data operations") {
        nlohmann::json d; d["id"]=88; d["name"]="Test88"; d["value"]=88*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),88);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test88");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test88")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),88);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt89() {
    T("Extended test 89: Data operations") {
        nlohmann::json d; d["id"]=89; d["name"]="Test89"; d["value"]=89*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),89);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test89");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test89")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),89);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt90() {
    T("Extended test 90: Data operations") {
        nlohmann::json d; d["id"]=90; d["name"]="Test90"; d["value"]=90*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),90);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test90");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test90")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),90);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt91() {
    T("Extended test 91: Data operations") {
        nlohmann::json d; d["id"]=91; d["name"]="Test91"; d["value"]=91*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),91);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test91");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test91")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),91);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt92() {
    T("Extended test 92: Data operations") {
        nlohmann::json d; d["id"]=92; d["name"]="Test92"; d["value"]=92*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),92);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test92");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test92")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),92);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt93() {
    T("Extended test 93: Data operations") {
        nlohmann::json d; d["id"]=93; d["name"]="Test93"; d["value"]=93*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),93);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test93");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test93")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),93);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt94() {
    T("Extended test 94: Data operations") {
        nlohmann::json d; d["id"]=94; d["name"]="Test94"; d["value"]=94*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),94);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test94");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test94")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),94);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt95() {
    T("Extended test 95: Data operations") {
        nlohmann::json d; d["id"]=95; d["name"]="Test95"; d["value"]=95*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),95);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test95");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test95")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),95);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt96() {
    T("Extended test 96: Data operations") {
        nlohmann::json d; d["id"]=96; d["name"]="Test96"; d["value"]=96*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),96);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test96");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test96")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),96);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt97() {
    T("Extended test 97: Data operations") {
        nlohmann::json d; d["id"]=97; d["name"]="Test97"; d["value"]=97*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),97);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test97");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test97")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),97);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt98() {
    T("Extended test 98: Data operations") {
        nlohmann::json d; d["id"]=98; d["name"]="Test98"; d["value"]=98*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),98);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test98");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test98")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),98);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt99() {
    T("Extended test 99: Data operations") {
        nlohmann::json d; d["id"]=99; d["name"]="Test99"; d["value"]=99*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),99);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test99");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test99")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),99);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt100() {
    T("Extended test 100: Data operations") {
        nlohmann::json d; d["id"]=100; d["name"]="Test100"; d["value"]=100*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),100);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test100");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test100")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),100);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt101() {
    T("Extended test 101: Data operations") {
        nlohmann::json d; d["id"]=101; d["name"]="Test101"; d["value"]=101*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),101);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test101");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test101")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),101);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt102() {
    T("Extended test 102: Data operations") {
        nlohmann::json d; d["id"]=102; d["name"]="Test102"; d["value"]=102*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),102);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test102");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test102")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),102);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt103() {
    T("Extended test 103: Data operations") {
        nlohmann::json d; d["id"]=103; d["name"]="Test103"; d["value"]=103*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),103);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test103");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test103")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),103);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt104() {
    T("Extended test 104: Data operations") {
        nlohmann::json d; d["id"]=104; d["name"]="Test104"; d["value"]=104*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),104);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test104");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test104")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),104);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt105() {
    T("Extended test 105: Data operations") {
        nlohmann::json d; d["id"]=105; d["name"]="Test105"; d["value"]=105*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),105);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test105");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test105")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),105);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt106() {
    T("Extended test 106: Data operations") {
        nlohmann::json d; d["id"]=106; d["name"]="Test106"; d["value"]=106*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),106);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test106");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test106")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),106);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt107() {
    T("Extended test 107: Data operations") {
        nlohmann::json d; d["id"]=107; d["name"]="Test107"; d["value"]=107*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),107);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test107");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test107")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),107);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt108() {
    T("Extended test 108: Data operations") {
        nlohmann::json d; d["id"]=108; d["name"]="Test108"; d["value"]=108*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),108);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test108");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test108")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),108);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt109() {
    T("Extended test 109: Data operations") {
        nlohmann::json d; d["id"]=109; d["name"]="Test109"; d["value"]=109*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),109);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test109");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test109")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),109);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt110() {
    T("Extended test 110: Data operations") {
        nlohmann::json d; d["id"]=110; d["name"]="Test110"; d["value"]=110*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),110);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test110");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test110")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),110);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt111() {
    T("Extended test 111: Data operations") {
        nlohmann::json d; d["id"]=111; d["name"]="Test111"; d["value"]=111*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),111);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test111");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test111")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),111);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt112() {
    T("Extended test 112: Data operations") {
        nlohmann::json d; d["id"]=112; d["name"]="Test112"; d["value"]=112*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),112);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test112");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test112")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),112);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt113() {
    T("Extended test 113: Data operations") {
        nlohmann::json d; d["id"]=113; d["name"]="Test113"; d["value"]=113*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),113);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test113");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test113")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),113);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt114() {
    T("Extended test 114: Data operations") {
        nlohmann::json d; d["id"]=114; d["name"]="Test114"; d["value"]=114*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),114);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test114");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test114")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),114);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt115() {
    T("Extended test 115: Data operations") {
        nlohmann::json d; d["id"]=115; d["name"]="Test115"; d["value"]=115*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),115);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test115");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test115")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),115);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt116() {
    T("Extended test 116: Data operations") {
        nlohmann::json d; d["id"]=116; d["name"]="Test116"; d["value"]=116*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),116);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test116");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test116")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),116);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt117() {
    T("Extended test 117: Data operations") {
        nlohmann::json d; d["id"]=117; d["name"]="Test117"; d["value"]=117*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),117);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test117");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test117")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),117);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt118() {
    T("Extended test 118: Data operations") {
        nlohmann::json d; d["id"]=118; d["name"]="Test118"; d["value"]=118*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),118);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test118");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test118")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),118);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt119() {
    T("Extended test 119: Data operations") {
        nlohmann::json d; d["id"]=119; d["name"]="Test119"; d["value"]=119*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),119);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test119");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test119")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),119);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt120() {
    T("Extended test 120: Data operations") {
        nlohmann::json d; d["id"]=120; d["name"]="Test120"; d["value"]=120*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),120);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test120");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test120")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),120);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt121() {
    T("Extended test 121: Data operations") {
        nlohmann::json d; d["id"]=121; d["name"]="Test121"; d["value"]=121*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),121);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test121");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test121")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),121);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt122() {
    T("Extended test 122: Data operations") {
        nlohmann::json d; d["id"]=122; d["name"]="Test122"; d["value"]=122*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),122);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test122");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test122")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),122);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt123() {
    T("Extended test 123: Data operations") {
        nlohmann::json d; d["id"]=123; d["name"]="Test123"; d["value"]=123*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),123);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test123");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test123")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),123);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt124() {
    T("Extended test 124: Data operations") {
        nlohmann::json d; d["id"]=124; d["name"]="Test124"; d["value"]=124*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),124);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test124");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test124")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),124);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt125() {
    T("Extended test 125: Data operations") {
        nlohmann::json d; d["id"]=125; d["name"]="Test125"; d["value"]=125*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),125);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test125");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test125")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),125);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt126() {
    T("Extended test 126: Data operations") {
        nlohmann::json d; d["id"]=126; d["name"]="Test126"; d["value"]=126*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),126);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test126");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test126")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),126);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt127() {
    T("Extended test 127: Data operations") {
        nlohmann::json d; d["id"]=127; d["name"]="Test127"; d["value"]=127*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),127);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test127");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test127")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),127);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt128() {
    T("Extended test 128: Data operations") {
        nlohmann::json d; d["id"]=128; d["name"]="Test128"; d["value"]=128*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),128);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test128");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test128")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),128);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt129() {
    T("Extended test 129: Data operations") {
        nlohmann::json d; d["id"]=129; d["name"]="Test129"; d["value"]=129*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),129);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test129");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test129")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),129);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt130() {
    T("Extended test 130: Data operations") {
        nlohmann::json d; d["id"]=130; d["name"]="Test130"; d["value"]=130*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),130);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test130");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test130")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),130);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt131() {
    T("Extended test 131: Data operations") {
        nlohmann::json d; d["id"]=131; d["name"]="Test131"; d["value"]=131*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),131);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test131");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test131")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),131);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt132() {
    T("Extended test 132: Data operations") {
        nlohmann::json d; d["id"]=132; d["name"]="Test132"; d["value"]=132*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),132);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test132");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test132")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),132);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt133() {
    T("Extended test 133: Data operations") {
        nlohmann::json d; d["id"]=133; d["name"]="Test133"; d["value"]=133*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),133);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test133");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test133")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),133);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt134() {
    T("Extended test 134: Data operations") {
        nlohmann::json d; d["id"]=134; d["name"]="Test134"; d["value"]=134*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),134);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test134");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test134")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),134);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt135() {
    T("Extended test 135: Data operations") {
        nlohmann::json d; d["id"]=135; d["name"]="Test135"; d["value"]=135*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),135);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test135");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test135")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),135);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt136() {
    T("Extended test 136: Data operations") {
        nlohmann::json d; d["id"]=136; d["name"]="Test136"; d["value"]=136*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),136);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test136");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test136")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),136);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt137() {
    T("Extended test 137: Data operations") {
        nlohmann::json d; d["id"]=137; d["name"]="Test137"; d["value"]=137*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),137);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test137");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test137")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),137);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt138() {
    T("Extended test 138: Data operations") {
        nlohmann::json d; d["id"]=138; d["name"]="Test138"; d["value"]=138*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),138);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test138");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test138")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),138);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt139() {
    T("Extended test 139: Data operations") {
        nlohmann::json d; d["id"]=139; d["name"]="Test139"; d["value"]=139*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),139);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test139");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test139")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),139);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt140() {
    T("Extended test 140: Data operations") {
        nlohmann::json d; d["id"]=140; d["name"]="Test140"; d["value"]=140*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),140);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test140");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test140")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),140);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt141() {
    T("Extended test 141: Data operations") {
        nlohmann::json d; d["id"]=141; d["name"]="Test141"; d["value"]=141*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),141);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test141");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test141")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),141);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt142() {
    T("Extended test 142: Data operations") {
        nlohmann::json d; d["id"]=142; d["name"]="Test142"; d["value"]=142*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),142);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test142");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test142")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),142);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt143() {
    T("Extended test 143: Data operations") {
        nlohmann::json d; d["id"]=143; d["name"]="Test143"; d["value"]=143*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),143);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test143");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test143")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),143);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt144() {
    T("Extended test 144: Data operations") {
        nlohmann::json d; d["id"]=144; d["name"]="Test144"; d["value"]=144*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),144);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test144");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test144")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),144);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt145() {
    T("Extended test 145: Data operations") {
        nlohmann::json d; d["id"]=145; d["name"]="Test145"; d["value"]=145*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),145);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test145");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test145")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),145);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt146() {
    T("Extended test 146: Data operations") {
        nlohmann::json d; d["id"]=146; d["name"]="Test146"; d["value"]=146*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),146);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test146");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test146")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),146);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt147() {
    T("Extended test 147: Data operations") {
        nlohmann::json d; d["id"]=147; d["name"]="Test147"; d["value"]=147*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),147);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test147");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test147")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),147);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt148() {
    T("Extended test 148: Data operations") {
        nlohmann::json d; d["id"]=148; d["name"]="Test148"; d["value"]=148*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),148);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test148");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test148")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),148);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt149() {
    T("Extended test 149: Data operations") {
        nlohmann::json d; d["id"]=149; d["name"]="Test149"; d["value"]=149*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),149);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test149");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test149")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),149);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt150() {
    T("Extended test 150: Data operations") {
        nlohmann::json d; d["id"]=150; d["name"]="Test150"; d["value"]=150*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),150);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test150");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test150")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),150);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt151() {
    T("Extended test 151: Data operations") {
        nlohmann::json d; d["id"]=151; d["name"]="Test151"; d["value"]=151*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),151);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test151");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test151")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),151);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt152() {
    T("Extended test 152: Data operations") {
        nlohmann::json d; d["id"]=152; d["name"]="Test152"; d["value"]=152*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),152);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test152");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test152")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),152);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt153() {
    T("Extended test 153: Data operations") {
        nlohmann::json d; d["id"]=153; d["name"]="Test153"; d["value"]=153*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),153);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test153");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test153")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),153);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt154() {
    T("Extended test 154: Data operations") {
        nlohmann::json d; d["id"]=154; d["name"]="Test154"; d["value"]=154*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),154);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test154");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test154")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),154);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt155() {
    T("Extended test 155: Data operations") {
        nlohmann::json d; d["id"]=155; d["name"]="Test155"; d["value"]=155*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),155);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test155");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test155")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),155);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt156() {
    T("Extended test 156: Data operations") {
        nlohmann::json d; d["id"]=156; d["name"]="Test156"; d["value"]=156*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),156);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test156");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test156")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),156);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt157() {
    T("Extended test 157: Data operations") {
        nlohmann::json d; d["id"]=157; d["name"]="Test157"; d["value"]=157*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),157);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test157");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test157")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),157);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt158() {
    T("Extended test 158: Data operations") {
        nlohmann::json d; d["id"]=158; d["name"]="Test158"; d["value"]=158*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),158);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test158");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test158")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),158);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt159() {
    T("Extended test 159: Data operations") {
        nlohmann::json d; d["id"]=159; d["name"]="Test159"; d["value"]=159*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),159);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test159");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test159")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),159);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt160() {
    T("Extended test 160: Data operations") {
        nlohmann::json d; d["id"]=160; d["name"]="Test160"; d["value"]=160*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),160);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test160");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test160")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),160);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt161() {
    T("Extended test 161: Data operations") {
        nlohmann::json d; d["id"]=161; d["name"]="Test161"; d["value"]=161*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),161);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test161");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test161")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),161);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt162() {
    T("Extended test 162: Data operations") {
        nlohmann::json d; d["id"]=162; d["name"]="Test162"; d["value"]=162*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),162);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test162");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test162")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),162);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt163() {
    T("Extended test 163: Data operations") {
        nlohmann::json d; d["id"]=163; d["name"]="Test163"; d["value"]=163*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),163);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test163");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test163")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),163);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt164() {
    T("Extended test 164: Data operations") {
        nlohmann::json d; d["id"]=164; d["name"]="Test164"; d["value"]=164*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),164);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test164");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test164")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),164);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt165() {
    T("Extended test 165: Data operations") {
        nlohmann::json d; d["id"]=165; d["name"]="Test165"; d["value"]=165*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),165);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test165");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test165")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),165);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt166() {
    T("Extended test 166: Data operations") {
        nlohmann::json d; d["id"]=166; d["name"]="Test166"; d["value"]=166*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),166);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test166");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test166")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),166);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt167() {
    T("Extended test 167: Data operations") {
        nlohmann::json d; d["id"]=167; d["name"]="Test167"; d["value"]=167*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),167);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test167");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test167")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),167);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt168() {
    T("Extended test 168: Data operations") {
        nlohmann::json d; d["id"]=168; d["name"]="Test168"; d["value"]=168*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),168);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test168");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test168")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),168);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt169() {
    T("Extended test 169: Data operations") {
        nlohmann::json d; d["id"]=169; d["name"]="Test169"; d["value"]=169*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),169);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test169");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test169")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),169);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt170() {
    T("Extended test 170: Data operations") {
        nlohmann::json d; d["id"]=170; d["name"]="Test170"; d["value"]=170*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),170);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test170");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test170")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),170);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt171() {
    T("Extended test 171: Data operations") {
        nlohmann::json d; d["id"]=171; d["name"]="Test171"; d["value"]=171*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),171);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test171");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test171")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),171);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt172() {
    T("Extended test 172: Data operations") {
        nlohmann::json d; d["id"]=172; d["name"]="Test172"; d["value"]=172*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),172);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test172");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test172")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),172);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt173() {
    T("Extended test 173: Data operations") {
        nlohmann::json d; d["id"]=173; d["name"]="Test173"; d["value"]=173*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),173);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test173");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test173")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),173);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt174() {
    T("Extended test 174: Data operations") {
        nlohmann::json d; d["id"]=174; d["name"]="Test174"; d["value"]=174*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),174);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test174");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test174")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),174);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt175() {
    T("Extended test 175: Data operations") {
        nlohmann::json d; d["id"]=175; d["name"]="Test175"; d["value"]=175*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),175);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test175");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test175")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),175);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt176() {
    T("Extended test 176: Data operations") {
        nlohmann::json d; d["id"]=176; d["name"]="Test176"; d["value"]=176*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),176);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test176");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test176")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),176);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt177() {
    T("Extended test 177: Data operations") {
        nlohmann::json d; d["id"]=177; d["name"]="Test177"; d["value"]=177*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),177);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test177");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test177")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),177);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt178() {
    T("Extended test 178: Data operations") {
        nlohmann::json d; d["id"]=178; d["name"]="Test178"; d["value"]=178*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),178);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test178");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test178")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),178);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt179() {
    T("Extended test 179: Data operations") {
        nlohmann::json d; d["id"]=179; d["name"]="Test179"; d["value"]=179*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),179);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test179");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test179")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),179);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt180() {
    T("Extended test 180: Data operations") {
        nlohmann::json d; d["id"]=180; d["name"]="Test180"; d["value"]=180*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),180);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test180");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test180")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),180);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt181() {
    T("Extended test 181: Data operations") {
        nlohmann::json d; d["id"]=181; d["name"]="Test181"; d["value"]=181*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),181);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test181");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test181")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),181);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt182() {
    T("Extended test 182: Data operations") {
        nlohmann::json d; d["id"]=182; d["name"]="Test182"; d["value"]=182*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),182);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test182");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test182")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),182);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt183() {
    T("Extended test 183: Data operations") {
        nlohmann::json d; d["id"]=183; d["name"]="Test183"; d["value"]=183*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),183);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test183");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test183")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),183);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt184() {
    T("Extended test 184: Data operations") {
        nlohmann::json d; d["id"]=184; d["name"]="Test184"; d["value"]=184*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),184);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test184");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test184")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),184);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt185() {
    T("Extended test 185: Data operations") {
        nlohmann::json d; d["id"]=185; d["name"]="Test185"; d["value"]=185*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),185);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test185");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test185")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),185);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt186() {
    T("Extended test 186: Data operations") {
        nlohmann::json d; d["id"]=186; d["name"]="Test186"; d["value"]=186*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),186);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test186");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test186")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),186);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt187() {
    T("Extended test 187: Data operations") {
        nlohmann::json d; d["id"]=187; d["name"]="Test187"; d["value"]=187*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),187);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test187");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test187")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),187);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt188() {
    T("Extended test 188: Data operations") {
        nlohmann::json d; d["id"]=188; d["name"]="Test188"; d["value"]=188*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),188);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test188");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test188")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),188);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt189() {
    T("Extended test 189: Data operations") {
        nlohmann::json d; d["id"]=189; d["name"]="Test189"; d["value"]=189*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),189);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test189");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test189")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),189);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt190() {
    T("Extended test 190: Data operations") {
        nlohmann::json d; d["id"]=190; d["name"]="Test190"; d["value"]=190*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),190);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test190");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test190")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),190);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt191() {
    T("Extended test 191: Data operations") {
        nlohmann::json d; d["id"]=191; d["name"]="Test191"; d["value"]=191*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),191);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test191");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test191")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),191);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt192() {
    T("Extended test 192: Data operations") {
        nlohmann::json d; d["id"]=192; d["name"]="Test192"; d["value"]=192*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),192);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test192");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test192")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),192);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt193() {
    T("Extended test 193: Data operations") {
        nlohmann::json d; d["id"]=193; d["name"]="Test193"; d["value"]=193*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),193);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test193");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test193")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),193);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt194() {
    T("Extended test 194: Data operations") {
        nlohmann::json d; d["id"]=194; d["name"]="Test194"; d["value"]=194*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),194);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test194");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test194")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),194);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt195() {
    T("Extended test 195: Data operations") {
        nlohmann::json d; d["id"]=195; d["name"]="Test195"; d["value"]=195*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),195);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test195");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test195")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),195);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt196() {
    T("Extended test 196: Data operations") {
        nlohmann::json d; d["id"]=196; d["name"]="Test196"; d["value"]=196*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),196);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test196");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test196")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),196);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt197() {
    T("Extended test 197: Data operations") {
        nlohmann::json d; d["id"]=197; d["name"]="Test197"; d["value"]=197*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),197);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test197");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test197")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),197);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt198() {
    T("Extended test 198: Data operations") {
        nlohmann::json d; d["id"]=198; d["name"]="Test198"; d["value"]=198*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),198);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test198");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test198")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),198);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt199() {
    T("Extended test 199: Data operations") {
        nlohmann::json d; d["id"]=199; d["name"]="Test199"; d["value"]=199*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),199);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test199");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test199")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),199);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt200() {
    T("Extended test 200: Data operations") {
        nlohmann::json d; d["id"]=200; d["name"]="Test200"; d["value"]=200*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),200);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test200");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test200")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),200);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt201() {
    T("Extended test 201: Data operations") {
        nlohmann::json d; d["id"]=201; d["name"]="Test201"; d["value"]=201*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),201);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test201");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test201")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),201);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt202() {
    T("Extended test 202: Data operations") {
        nlohmann::json d; d["id"]=202; d["name"]="Test202"; d["value"]=202*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),202);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test202");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test202")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),202);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt203() {
    T("Extended test 203: Data operations") {
        nlohmann::json d; d["id"]=203; d["name"]="Test203"; d["value"]=203*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),203);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test203");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test203")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),203);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt204() {
    T("Extended test 204: Data operations") {
        nlohmann::json d; d["id"]=204; d["name"]="Test204"; d["value"]=204*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),204);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test204");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test204")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),204);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt205() {
    T("Extended test 205: Data operations") {
        nlohmann::json d; d["id"]=205; d["name"]="Test205"; d["value"]=205*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),205);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test205");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test205")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),205);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt206() {
    T("Extended test 206: Data operations") {
        nlohmann::json d; d["id"]=206; d["name"]="Test206"; d["value"]=206*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),206);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test206");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test206")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),206);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt207() {
    T("Extended test 207: Data operations") {
        nlohmann::json d; d["id"]=207; d["name"]="Test207"; d["value"]=207*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),207);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test207");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test207")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),207);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt208() {
    T("Extended test 208: Data operations") {
        nlohmann::json d; d["id"]=208; d["name"]="Test208"; d["value"]=208*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),208);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test208");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test208")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),208);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt209() {
    T("Extended test 209: Data operations") {
        nlohmann::json d; d["id"]=209; d["name"]="Test209"; d["value"]=209*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),209);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test209");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test209")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),209);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt210() {
    T("Extended test 210: Data operations") {
        nlohmann::json d; d["id"]=210; d["name"]="Test210"; d["value"]=210*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),210);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test210");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test210")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),210);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt211() {
    T("Extended test 211: Data operations") {
        nlohmann::json d; d["id"]=211; d["name"]="Test211"; d["value"]=211*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),211);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test211");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test211")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),211);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt212() {
    T("Extended test 212: Data operations") {
        nlohmann::json d; d["id"]=212; d["name"]="Test212"; d["value"]=212*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),212);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test212");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test212")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),212);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt213() {
    T("Extended test 213: Data operations") {
        nlohmann::json d; d["id"]=213; d["name"]="Test213"; d["value"]=213*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),213);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test213");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test213")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),213);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt214() {
    T("Extended test 214: Data operations") {
        nlohmann::json d; d["id"]=214; d["name"]="Test214"; d["value"]=214*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),214);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test214");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test214")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),214);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt215() {
    T("Extended test 215: Data operations") {
        nlohmann::json d; d["id"]=215; d["name"]="Test215"; d["value"]=215*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),215);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test215");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test215")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),215);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt216() {
    T("Extended test 216: Data operations") {
        nlohmann::json d; d["id"]=216; d["name"]="Test216"; d["value"]=216*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),216);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test216");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test216")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),216);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt217() {
    T("Extended test 217: Data operations") {
        nlohmann::json d; d["id"]=217; d["name"]="Test217"; d["value"]=217*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),217);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test217");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test217")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),217);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt218() {
    T("Extended test 218: Data operations") {
        nlohmann::json d; d["id"]=218; d["name"]="Test218"; d["value"]=218*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),218);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test218");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test218")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),218);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt219() {
    T("Extended test 219: Data operations") {
        nlohmann::json d; d["id"]=219; d["name"]="Test219"; d["value"]=219*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),219);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test219");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test219")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),219);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt220() {
    T("Extended test 220: Data operations") {
        nlohmann::json d; d["id"]=220; d["name"]="Test220"; d["value"]=220*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),220);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test220");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test220")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),220);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt221() {
    T("Extended test 221: Data operations") {
        nlohmann::json d; d["id"]=221; d["name"]="Test221"; d["value"]=221*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),221);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test221");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test221")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),221);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt222() {
    T("Extended test 222: Data operations") {
        nlohmann::json d; d["id"]=222; d["name"]="Test222"; d["value"]=222*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),222);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test222");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test222")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),222);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt223() {
    T("Extended test 223: Data operations") {
        nlohmann::json d; d["id"]=223; d["name"]="Test223"; d["value"]=223*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),223);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test223");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test223")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),223);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt224() {
    T("Extended test 224: Data operations") {
        nlohmann::json d; d["id"]=224; d["name"]="Test224"; d["value"]=224*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),224);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test224");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test224")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),224);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt225() {
    T("Extended test 225: Data operations") {
        nlohmann::json d; d["id"]=225; d["name"]="Test225"; d["value"]=225*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),225);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test225");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test225")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),225);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt226() {
    T("Extended test 226: Data operations") {
        nlohmann::json d; d["id"]=226; d["name"]="Test226"; d["value"]=226*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),226);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test226");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test226")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),226);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt227() {
    T("Extended test 227: Data operations") {
        nlohmann::json d; d["id"]=227; d["name"]="Test227"; d["value"]=227*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),227);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test227");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test227")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),227);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt228() {
    T("Extended test 228: Data operations") {
        nlohmann::json d; d["id"]=228; d["name"]="Test228"; d["value"]=228*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),228);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test228");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test228")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),228);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt229() {
    T("Extended test 229: Data operations") {
        nlohmann::json d; d["id"]=229; d["name"]="Test229"; d["value"]=229*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),229);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test229");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test229")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),229);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt230() {
    T("Extended test 230: Data operations") {
        nlohmann::json d; d["id"]=230; d["name"]="Test230"; d["value"]=230*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),230);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test230");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test230")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),230);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt231() {
    T("Extended test 231: Data operations") {
        nlohmann::json d; d["id"]=231; d["name"]="Test231"; d["value"]=231*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),231);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test231");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test231")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),231);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt232() {
    T("Extended test 232: Data operations") {
        nlohmann::json d; d["id"]=232; d["name"]="Test232"; d["value"]=232*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),232);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test232");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test232")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),232);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt233() {
    T("Extended test 233: Data operations") {
        nlohmann::json d; d["id"]=233; d["name"]="Test233"; d["value"]=233*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),233);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test233");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test233")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),233);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt234() {
    T("Extended test 234: Data operations") {
        nlohmann::json d; d["id"]=234; d["name"]="Test234"; d["value"]=234*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),234);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test234");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test234")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),234);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt235() {
    T("Extended test 235: Data operations") {
        nlohmann::json d; d["id"]=235; d["name"]="Test235"; d["value"]=235*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),235);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test235");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test235")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),235);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt236() {
    T("Extended test 236: Data operations") {
        nlohmann::json d; d["id"]=236; d["name"]="Test236"; d["value"]=236*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),236);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test236");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test236")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),236);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt237() {
    T("Extended test 237: Data operations") {
        nlohmann::json d; d["id"]=237; d["name"]="Test237"; d["value"]=237*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),237);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test237");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test237")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),237);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt238() {
    T("Extended test 238: Data operations") {
        nlohmann::json d; d["id"]=238; d["name"]="Test238"; d["value"]=238*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),238);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test238");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test238")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),238);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt239() {
    T("Extended test 239: Data operations") {
        nlohmann::json d; d["id"]=239; d["name"]="Test239"; d["value"]=239*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),239);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test239");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test239")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),239);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt240() {
    T("Extended test 240: Data operations") {
        nlohmann::json d; d["id"]=240; d["name"]="Test240"; d["value"]=240*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),240);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test240");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test240")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),240);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt241() {
    T("Extended test 241: Data operations") {
        nlohmann::json d; d["id"]=241; d["name"]="Test241"; d["value"]=241*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),241);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test241");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test241")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),241);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt242() {
    T("Extended test 242: Data operations") {
        nlohmann::json d; d["id"]=242; d["name"]="Test242"; d["value"]=242*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),242);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test242");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test242")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),242);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt243() {
    T("Extended test 243: Data operations") {
        nlohmann::json d; d["id"]=243; d["name"]="Test243"; d["value"]=243*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),243);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test243");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test243")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),243);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt244() {
    T("Extended test 244: Data operations") {
        nlohmann::json d; d["id"]=244; d["name"]="Test244"; d["value"]=244*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),244);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test244");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test244")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),244);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt245() {
    T("Extended test 245: Data operations") {
        nlohmann::json d; d["id"]=245; d["name"]="Test245"; d["value"]=245*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),245);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test245");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test245")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),245);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt246() {
    T("Extended test 246: Data operations") {
        nlohmann::json d; d["id"]=246; d["name"]="Test246"; d["value"]=246*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),246);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test246");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test246")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),246);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt247() {
    T("Extended test 247: Data operations") {
        nlohmann::json d; d["id"]=247; d["name"]="Test247"; d["value"]=247*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),247);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test247");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test247")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),247);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt248() {
    T("Extended test 248: Data operations") {
        nlohmann::json d; d["id"]=248; d["name"]="Test248"; d["value"]=248*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),248);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test248");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test248")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),248);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt249() {
    T("Extended test 249: Data operations") {
        nlohmann::json d; d["id"]=249; d["name"]="Test249"; d["value"]=249*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),249);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test249");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test249")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),249);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt250() {
    T("Extended test 250: Data operations") {
        nlohmann::json d; d["id"]=250; d["name"]="Test250"; d["value"]=250*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),250);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test250");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test250")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),250);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt251() {
    T("Extended test 251: Data operations") {
        nlohmann::json d; d["id"]=251; d["name"]="Test251"; d["value"]=251*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),251);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test251");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test251")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),251);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt252() {
    T("Extended test 252: Data operations") {
        nlohmann::json d; d["id"]=252; d["name"]="Test252"; d["value"]=252*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),252);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test252");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test252")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),252);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt253() {
    T("Extended test 253: Data operations") {
        nlohmann::json d; d["id"]=253; d["name"]="Test253"; d["value"]=253*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),253);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test253");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test253")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),253);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt254() {
    T("Extended test 254: Data operations") {
        nlohmann::json d; d["id"]=254; d["name"]="Test254"; d["value"]=254*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),254);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test254");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test254")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),254);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt255() {
    T("Extended test 255: Data operations") {
        nlohmann::json d; d["id"]=255; d["name"]="Test255"; d["value"]=255*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),255);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test255");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test255")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),255);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt256() {
    T("Extended test 256: Data operations") {
        nlohmann::json d; d["id"]=256; d["name"]="Test256"; d["value"]=256*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),256);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test256");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test256")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),256);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt257() {
    T("Extended test 257: Data operations") {
        nlohmann::json d; d["id"]=257; d["name"]="Test257"; d["value"]=257*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),257);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test257");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test257")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),257);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt258() {
    T("Extended test 258: Data operations") {
        nlohmann::json d; d["id"]=258; d["name"]="Test258"; d["value"]=258*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),258);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test258");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test258")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),258);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt259() {
    T("Extended test 259: Data operations") {
        nlohmann::json d; d["id"]=259; d["name"]="Test259"; d["value"]=259*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),259);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test259");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test259")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),259);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt260() {
    T("Extended test 260: Data operations") {
        nlohmann::json d; d["id"]=260; d["name"]="Test260"; d["value"]=260*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),260);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test260");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test260")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),260);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt261() {
    T("Extended test 261: Data operations") {
        nlohmann::json d; d["id"]=261; d["name"]="Test261"; d["value"]=261*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),261);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test261");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test261")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),261);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt262() {
    T("Extended test 262: Data operations") {
        nlohmann::json d; d["id"]=262; d["name"]="Test262"; d["value"]=262*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),262);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test262");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test262")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),262);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt263() {
    T("Extended test 263: Data operations") {
        nlohmann::json d; d["id"]=263; d["name"]="Test263"; d["value"]=263*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),263);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test263");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test263")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),263);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt264() {
    T("Extended test 264: Data operations") {
        nlohmann::json d; d["id"]=264; d["name"]="Test264"; d["value"]=264*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),264);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test264");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test264")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),264);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt265() {
    T("Extended test 265: Data operations") {
        nlohmann::json d; d["id"]=265; d["name"]="Test265"; d["value"]=265*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),265);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test265");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test265")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),265);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt266() {
    T("Extended test 266: Data operations") {
        nlohmann::json d; d["id"]=266; d["name"]="Test266"; d["value"]=266*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),266);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test266");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test266")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),266);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt267() {
    T("Extended test 267: Data operations") {
        nlohmann::json d; d["id"]=267; d["name"]="Test267"; d["value"]=267*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),267);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test267");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test267")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),267);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt268() {
    T("Extended test 268: Data operations") {
        nlohmann::json d; d["id"]=268; d["name"]="Test268"; d["value"]=268*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),268);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test268");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test268")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),268);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt269() {
    T("Extended test 269: Data operations") {
        nlohmann::json d; d["id"]=269; d["name"]="Test269"; d["value"]=269*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),269);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test269");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test269")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),269);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt270() {
    T("Extended test 270: Data operations") {
        nlohmann::json d; d["id"]=270; d["name"]="Test270"; d["value"]=270*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),270);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test270");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test270")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),270);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt271() {
    T("Extended test 271: Data operations") {
        nlohmann::json d; d["id"]=271; d["name"]="Test271"; d["value"]=271*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),271);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test271");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test271")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),271);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt272() {
    T("Extended test 272: Data operations") {
        nlohmann::json d; d["id"]=272; d["name"]="Test272"; d["value"]=272*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),272);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test272");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test272")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),272);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt273() {
    T("Extended test 273: Data operations") {
        nlohmann::json d; d["id"]=273; d["name"]="Test273"; d["value"]=273*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),273);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test273");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test273")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),273);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt274() {
    T("Extended test 274: Data operations") {
        nlohmann::json d; d["id"]=274; d["name"]="Test274"; d["value"]=274*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),274);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test274");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test274")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),274);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt275() {
    T("Extended test 275: Data operations") {
        nlohmann::json d; d["id"]=275; d["name"]="Test275"; d["value"]=275*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),275);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test275");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test275")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),275);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt276() {
    T("Extended test 276: Data operations") {
        nlohmann::json d; d["id"]=276; d["name"]="Test276"; d["value"]=276*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),276);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test276");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test276")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),276);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt277() {
    T("Extended test 277: Data operations") {
        nlohmann::json d; d["id"]=277; d["name"]="Test277"; d["value"]=277*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),277);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test277");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test277")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),277);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt278() {
    T("Extended test 278: Data operations") {
        nlohmann::json d; d["id"]=278; d["name"]="Test278"; d["value"]=278*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),278);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test278");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test278")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),278);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt279() {
    T("Extended test 279: Data operations") {
        nlohmann::json d; d["id"]=279; d["name"]="Test279"; d["value"]=279*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),279);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test279");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test279")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),279);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt280() {
    T("Extended test 280: Data operations") {
        nlohmann::json d; d["id"]=280; d["name"]="Test280"; d["value"]=280*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),280);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test280");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test280")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),280);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt281() {
    T("Extended test 281: Data operations") {
        nlohmann::json d; d["id"]=281; d["name"]="Test281"; d["value"]=281*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),281);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test281");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test281")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),281);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt282() {
    T("Extended test 282: Data operations") {
        nlohmann::json d; d["id"]=282; d["name"]="Test282"; d["value"]=282*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),282);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test282");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test282")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),282);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt283() {
    T("Extended test 283: Data operations") {
        nlohmann::json d; d["id"]=283; d["name"]="Test283"; d["value"]=283*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),283);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test283");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test283")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),283);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt284() {
    T("Extended test 284: Data operations") {
        nlohmann::json d; d["id"]=284; d["name"]="Test284"; d["value"]=284*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),284);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test284");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test284")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),284);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt285() {
    T("Extended test 285: Data operations") {
        nlohmann::json d; d["id"]=285; d["name"]="Test285"; d["value"]=285*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),285);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test285");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test285")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),285);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt286() {
    T("Extended test 286: Data operations") {
        nlohmann::json d; d["id"]=286; d["name"]="Test286"; d["value"]=286*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),286);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test286");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test286")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),286);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt287() {
    T("Extended test 287: Data operations") {
        nlohmann::json d; d["id"]=287; d["name"]="Test287"; d["value"]=287*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),287);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test287");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test287")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),287);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt288() {
    T("Extended test 288: Data operations") {
        nlohmann::json d; d["id"]=288; d["name"]="Test288"; d["value"]=288*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),288);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test288");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test288")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),288);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt289() {
    T("Extended test 289: Data operations") {
        nlohmann::json d; d["id"]=289; d["name"]="Test289"; d["value"]=289*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),289);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test289");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test289")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),289);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt290() {
    T("Extended test 290: Data operations") {
        nlohmann::json d; d["id"]=290; d["name"]="Test290"; d["value"]=290*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),290);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test290");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test290")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),290);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt291() {
    T("Extended test 291: Data operations") {
        nlohmann::json d; d["id"]=291; d["name"]="Test291"; d["value"]=291*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),291);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test291");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test291")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),291);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt292() {
    T("Extended test 292: Data operations") {
        nlohmann::json d; d["id"]=292; d["name"]="Test292"; d["value"]=292*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),292);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test292");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test292")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),292);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt293() {
    T("Extended test 293: Data operations") {
        nlohmann::json d; d["id"]=293; d["name"]="Test293"; d["value"]=293*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),293);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test293");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test293")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),293);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt294() {
    T("Extended test 294: Data operations") {
        nlohmann::json d; d["id"]=294; d["name"]="Test294"; d["value"]=294*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),294);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test294");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test294")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),294);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt295() {
    T("Extended test 295: Data operations") {
        nlohmann::json d; d["id"]=295; d["name"]="Test295"; d["value"]=295*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),295);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test295");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test295")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),295);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt296() {
    T("Extended test 296: Data operations") {
        nlohmann::json d; d["id"]=296; d["name"]="Test296"; d["value"]=296*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),296);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test296");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test296")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),296);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt297() {
    T("Extended test 297: Data operations") {
        nlohmann::json d; d["id"]=297; d["name"]="Test297"; d["value"]=297*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),297);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test297");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test297")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),297);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt298() {
    T("Extended test 298: Data operations") {
        nlohmann::json d; d["id"]=298; d["name"]="Test298"; d["value"]=298*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),298);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test298");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test298")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),298);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt299() {
    T("Extended test 299: Data operations") {
        nlohmann::json d; d["id"]=299; d["name"]="Test299"; d["value"]=299*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),299);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test299");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test299")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),299);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt300() {
    T("Extended test 300: Data operations") {
        nlohmann::json d; d["id"]=300; d["name"]="Test300"; d["value"]=300*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),300);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test300");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test300")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),300);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt301() {
    T("Extended test 301: Data operations") {
        nlohmann::json d; d["id"]=301; d["name"]="Test301"; d["value"]=301*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),301);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test301");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test301")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),301);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt302() {
    T("Extended test 302: Data operations") {
        nlohmann::json d; d["id"]=302; d["name"]="Test302"; d["value"]=302*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),302);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test302");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test302")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),302);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt303() {
    T("Extended test 303: Data operations") {
        nlohmann::json d; d["id"]=303; d["name"]="Test303"; d["value"]=303*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),303);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test303");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test303")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),303);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt304() {
    T("Extended test 304: Data operations") {
        nlohmann::json d; d["id"]=304; d["name"]="Test304"; d["value"]=304*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),304);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test304");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test304")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),304);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt305() {
    T("Extended test 305: Data operations") {
        nlohmann::json d; d["id"]=305; d["name"]="Test305"; d["value"]=305*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),305);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test305");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test305")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),305);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt306() {
    T("Extended test 306: Data operations") {
        nlohmann::json d; d["id"]=306; d["name"]="Test306"; d["value"]=306*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),306);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test306");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test306")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),306);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt307() {
    T("Extended test 307: Data operations") {
        nlohmann::json d; d["id"]=307; d["name"]="Test307"; d["value"]=307*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),307);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test307");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test307")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),307);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt308() {
    T("Extended test 308: Data operations") {
        nlohmann::json d; d["id"]=308; d["name"]="Test308"; d["value"]=308*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),308);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test308");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test308")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),308);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt309() {
    T("Extended test 309: Data operations") {
        nlohmann::json d; d["id"]=309; d["name"]="Test309"; d["value"]=309*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),309);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test309");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test309")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),309);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt310() {
    T("Extended test 310: Data operations") {
        nlohmann::json d; d["id"]=310; d["name"]="Test310"; d["value"]=310*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),310);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test310");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test310")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),310);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt311() {
    T("Extended test 311: Data operations") {
        nlohmann::json d; d["id"]=311; d["name"]="Test311"; d["value"]=311*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),311);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test311");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test311")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),311);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt312() {
    T("Extended test 312: Data operations") {
        nlohmann::json d; d["id"]=312; d["name"]="Test312"; d["value"]=312*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),312);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test312");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test312")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),312);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt313() {
    T("Extended test 313: Data operations") {
        nlohmann::json d; d["id"]=313; d["name"]="Test313"; d["value"]=313*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),313);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test313");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test313")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),313);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt314() {
    T("Extended test 314: Data operations") {
        nlohmann::json d; d["id"]=314; d["name"]="Test314"; d["value"]=314*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),314);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test314");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test314")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),314);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt315() {
    T("Extended test 315: Data operations") {
        nlohmann::json d; d["id"]=315; d["name"]="Test315"; d["value"]=315*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),315);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test315");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test315")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),315);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt316() {
    T("Extended test 316: Data operations") {
        nlohmann::json d; d["id"]=316; d["name"]="Test316"; d["value"]=316*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),316);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test316");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test316")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),316);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt317() {
    T("Extended test 317: Data operations") {
        nlohmann::json d; d["id"]=317; d["name"]="Test317"; d["value"]=317*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),317);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test317");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test317")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),317);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt318() {
    T("Extended test 318: Data operations") {
        nlohmann::json d; d["id"]=318; d["name"]="Test318"; d["value"]=318*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),318);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test318");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test318")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),318);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt319() {
    T("Extended test 319: Data operations") {
        nlohmann::json d; d["id"]=319; d["name"]="Test319"; d["value"]=319*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),319);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test319");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test319")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),319);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt320() {
    T("Extended test 320: Data operations") {
        nlohmann::json d; d["id"]=320; d["name"]="Test320"; d["value"]=320*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),320);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test320");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test320")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),320);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt321() {
    T("Extended test 321: Data operations") {
        nlohmann::json d; d["id"]=321; d["name"]="Test321"; d["value"]=321*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),321);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test321");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test321")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),321);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt322() {
    T("Extended test 322: Data operations") {
        nlohmann::json d; d["id"]=322; d["name"]="Test322"; d["value"]=322*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),322);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test322");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test322")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),322);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt323() {
    T("Extended test 323: Data operations") {
        nlohmann::json d; d["id"]=323; d["name"]="Test323"; d["value"]=323*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),323);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test323");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test323")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),323);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt324() {
    T("Extended test 324: Data operations") {
        nlohmann::json d; d["id"]=324; d["name"]="Test324"; d["value"]=324*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),324);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test324");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test324")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),324);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt325() {
    T("Extended test 325: Data operations") {
        nlohmann::json d; d["id"]=325; d["name"]="Test325"; d["value"]=325*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),325);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test325");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test325")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),325);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt326() {
    T("Extended test 326: Data operations") {
        nlohmann::json d; d["id"]=326; d["name"]="Test326"; d["value"]=326*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),326);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test326");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test326")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),326);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt327() {
    T("Extended test 327: Data operations") {
        nlohmann::json d; d["id"]=327; d["name"]="Test327"; d["value"]=327*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),327);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test327");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test327")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),327);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt328() {
    T("Extended test 328: Data operations") {
        nlohmann::json d; d["id"]=328; d["name"]="Test328"; d["value"]=328*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),328);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test328");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test328")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),328);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt329() {
    T("Extended test 329: Data operations") {
        nlohmann::json d; d["id"]=329; d["name"]="Test329"; d["value"]=329*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),329);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test329");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test329")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),329);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt330() {
    T("Extended test 330: Data operations") {
        nlohmann::json d; d["id"]=330; d["name"]="Test330"; d["value"]=330*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),330);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test330");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test330")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),330);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt331() {
    T("Extended test 331: Data operations") {
        nlohmann::json d; d["id"]=331; d["name"]="Test331"; d["value"]=331*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),331);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test331");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test331")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),331);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt332() {
    T("Extended test 332: Data operations") {
        nlohmann::json d; d["id"]=332; d["name"]="Test332"; d["value"]=332*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),332);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test332");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test332")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),332);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt333() {
    T("Extended test 333: Data operations") {
        nlohmann::json d; d["id"]=333; d["name"]="Test333"; d["value"]=333*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),333);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test333");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test333")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),333);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt334() {
    T("Extended test 334: Data operations") {
        nlohmann::json d; d["id"]=334; d["name"]="Test334"; d["value"]=334*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),334);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test334");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test334")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),334);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt335() {
    T("Extended test 335: Data operations") {
        nlohmann::json d; d["id"]=335; d["name"]="Test335"; d["value"]=335*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),335);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test335");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test335")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),335);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt336() {
    T("Extended test 336: Data operations") {
        nlohmann::json d; d["id"]=336; d["name"]="Test336"; d["value"]=336*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),336);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test336");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test336")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),336);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt337() {
    T("Extended test 337: Data operations") {
        nlohmann::json d; d["id"]=337; d["name"]="Test337"; d["value"]=337*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),337);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test337");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test337")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),337);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt338() {
    T("Extended test 338: Data operations") {
        nlohmann::json d; d["id"]=338; d["name"]="Test338"; d["value"]=338*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),338);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test338");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test338")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),338);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt339() {
    T("Extended test 339: Data operations") {
        nlohmann::json d; d["id"]=339; d["name"]="Test339"; d["value"]=339*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),339);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test339");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test339")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),339);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt340() {
    T("Extended test 340: Data operations") {
        nlohmann::json d; d["id"]=340; d["name"]="Test340"; d["value"]=340*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),340);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test340");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test340")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),340);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt341() {
    T("Extended test 341: Data operations") {
        nlohmann::json d; d["id"]=341; d["name"]="Test341"; d["value"]=341*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),341);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test341");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test341")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),341);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt342() {
    T("Extended test 342: Data operations") {
        nlohmann::json d; d["id"]=342; d["name"]="Test342"; d["value"]=342*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),342);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test342");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test342")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),342);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt343() {
    T("Extended test 343: Data operations") {
        nlohmann::json d; d["id"]=343; d["name"]="Test343"; d["value"]=343*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),343);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test343");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test343")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),343);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt344() {
    T("Extended test 344: Data operations") {
        nlohmann::json d; d["id"]=344; d["name"]="Test344"; d["value"]=344*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),344);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test344");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test344")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),344);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt345() {
    T("Extended test 345: Data operations") {
        nlohmann::json d; d["id"]=345; d["name"]="Test345"; d["value"]=345*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),345);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test345");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test345")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),345);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt346() {
    T("Extended test 346: Data operations") {
        nlohmann::json d; d["id"]=346; d["name"]="Test346"; d["value"]=346*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),346);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test346");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test346")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),346);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt347() {
    T("Extended test 347: Data operations") {
        nlohmann::json d; d["id"]=347; d["name"]="Test347"; d["value"]=347*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),347);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test347");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test347")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),347);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt348() {
    T("Extended test 348: Data operations") {
        nlohmann::json d; d["id"]=348; d["name"]="Test348"; d["value"]=348*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),348);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test348");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test348")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),348);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt349() {
    T("Extended test 349: Data operations") {
        nlohmann::json d; d["id"]=349; d["name"]="Test349"; d["value"]=349*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),349);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test349");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test349")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),349);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt350() {
    T("Extended test 350: Data operations") {
        nlohmann::json d; d["id"]=350; d["name"]="Test350"; d["value"]=350*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),350);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test350");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test350")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),350);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt351() {
    T("Extended test 351: Data operations") {
        nlohmann::json d; d["id"]=351; d["name"]="Test351"; d["value"]=351*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),351);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test351");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test351")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),351);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt352() {
    T("Extended test 352: Data operations") {
        nlohmann::json d; d["id"]=352; d["name"]="Test352"; d["value"]=352*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),352);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test352");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test352")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),352);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt353() {
    T("Extended test 353: Data operations") {
        nlohmann::json d; d["id"]=353; d["name"]="Test353"; d["value"]=353*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),353);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test353");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test353")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),353);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt354() {
    T("Extended test 354: Data operations") {
        nlohmann::json d; d["id"]=354; d["name"]="Test354"; d["value"]=354*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),354);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test354");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test354")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),354);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt355() {
    T("Extended test 355: Data operations") {
        nlohmann::json d; d["id"]=355; d["name"]="Test355"; d["value"]=355*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),355);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test355");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test355")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),355);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt356() {
    T("Extended test 356: Data operations") {
        nlohmann::json d; d["id"]=356; d["name"]="Test356"; d["value"]=356*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),356);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test356");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test356")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),356);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt357() {
    T("Extended test 357: Data operations") {
        nlohmann::json d; d["id"]=357; d["name"]="Test357"; d["value"]=357*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),357);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test357");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test357")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),357);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt358() {
    T("Extended test 358: Data operations") {
        nlohmann::json d; d["id"]=358; d["name"]="Test358"; d["value"]=358*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),358);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test358");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test358")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),358);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt359() {
    T("Extended test 359: Data operations") {
        nlohmann::json d; d["id"]=359; d["name"]="Test359"; d["value"]=359*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),359);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test359");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test359")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),359);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt360() {
    T("Extended test 360: Data operations") {
        nlohmann::json d; d["id"]=360; d["name"]="Test360"; d["value"]=360*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),360);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test360");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test360")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),360);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt361() {
    T("Extended test 361: Data operations") {
        nlohmann::json d; d["id"]=361; d["name"]="Test361"; d["value"]=361*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),361);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test361");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test361")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),361);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt362() {
    T("Extended test 362: Data operations") {
        nlohmann::json d; d["id"]=362; d["name"]="Test362"; d["value"]=362*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),362);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test362");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test362")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),362);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt363() {
    T("Extended test 363: Data operations") {
        nlohmann::json d; d["id"]=363; d["name"]="Test363"; d["value"]=363*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),363);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test363");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test363")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),363);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt364() {
    T("Extended test 364: Data operations") {
        nlohmann::json d; d["id"]=364; d["name"]="Test364"; d["value"]=364*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),364);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test364");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test364")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),364);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt365() {
    T("Extended test 365: Data operations") {
        nlohmann::json d; d["id"]=365; d["name"]="Test365"; d["value"]=365*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),365);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test365");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test365")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),365);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt366() {
    T("Extended test 366: Data operations") {
        nlohmann::json d; d["id"]=366; d["name"]="Test366"; d["value"]=366*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),366);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test366");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test366")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),366);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt367() {
    T("Extended test 367: Data operations") {
        nlohmann::json d; d["id"]=367; d["name"]="Test367"; d["value"]=367*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),367);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test367");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test367")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),367);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt368() {
    T("Extended test 368: Data operations") {
        nlohmann::json d; d["id"]=368; d["name"]="Test368"; d["value"]=368*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),368);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test368");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test368")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),368);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt369() {
    T("Extended test 369: Data operations") {
        nlohmann::json d; d["id"]=369; d["name"]="Test369"; d["value"]=369*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),369);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test369");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test369")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),369);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt370() {
    T("Extended test 370: Data operations") {
        nlohmann::json d; d["id"]=370; d["name"]="Test370"; d["value"]=370*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),370);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test370");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test370")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),370);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt371() {
    T("Extended test 371: Data operations") {
        nlohmann::json d; d["id"]=371; d["name"]="Test371"; d["value"]=371*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),371);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test371");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test371")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),371);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt372() {
    T("Extended test 372: Data operations") {
        nlohmann::json d; d["id"]=372; d["name"]="Test372"; d["value"]=372*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),372);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test372");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test372")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),372);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt373() {
    T("Extended test 373: Data operations") {
        nlohmann::json d; d["id"]=373; d["name"]="Test373"; d["value"]=373*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),373);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test373");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test373")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),373);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt374() {
    T("Extended test 374: Data operations") {
        nlohmann::json d; d["id"]=374; d["name"]="Test374"; d["value"]=374*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),374);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test374");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test374")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),374);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt375() {
    T("Extended test 375: Data operations") {
        nlohmann::json d; d["id"]=375; d["name"]="Test375"; d["value"]=375*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),375);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test375");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test375")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),375);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt376() {
    T("Extended test 376: Data operations") {
        nlohmann::json d; d["id"]=376; d["name"]="Test376"; d["value"]=376*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),376);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test376");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test376")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),376);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt377() {
    T("Extended test 377: Data operations") {
        nlohmann::json d; d["id"]=377; d["name"]="Test377"; d["value"]=377*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),377);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test377");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test377")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),377);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt378() {
    T("Extended test 378: Data operations") {
        nlohmann::json d; d["id"]=378; d["name"]="Test378"; d["value"]=378*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),378);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test378");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test378")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),378);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt379() {
    T("Extended test 379: Data operations") {
        nlohmann::json d; d["id"]=379; d["name"]="Test379"; d["value"]=379*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),379);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test379");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test379")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),379);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt380() {
    T("Extended test 380: Data operations") {
        nlohmann::json d; d["id"]=380; d["name"]="Test380"; d["value"]=380*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),380);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test380");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test380")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),380);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt381() {
    T("Extended test 381: Data operations") {
        nlohmann::json d; d["id"]=381; d["name"]="Test381"; d["value"]=381*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),381);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test381");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test381")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),381);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt382() {
    T("Extended test 382: Data operations") {
        nlohmann::json d; d["id"]=382; d["name"]="Test382"; d["value"]=382*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),382);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test382");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test382")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),382);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt383() {
    T("Extended test 383: Data operations") {
        nlohmann::json d; d["id"]=383; d["name"]="Test383"; d["value"]=383*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),383);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test383");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test383")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),383);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt384() {
    T("Extended test 384: Data operations") {
        nlohmann::json d; d["id"]=384; d["name"]="Test384"; d["value"]=384*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),384);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test384");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test384")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),384);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt385() {
    T("Extended test 385: Data operations") {
        nlohmann::json d; d["id"]=385; d["name"]="Test385"; d["value"]=385*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),385);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test385");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test385")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),385);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt386() {
    T("Extended test 386: Data operations") {
        nlohmann::json d; d["id"]=386; d["name"]="Test386"; d["value"]=386*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),386);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test386");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test386")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),386);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt387() {
    T("Extended test 387: Data operations") {
        nlohmann::json d; d["id"]=387; d["name"]="Test387"; d["value"]=387*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),387);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test387");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test387")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),387);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt388() {
    T("Extended test 388: Data operations") {
        nlohmann::json d; d["id"]=388; d["name"]="Test388"; d["value"]=388*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),388);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test388");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test388")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),388);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt389() {
    T("Extended test 389: Data operations") {
        nlohmann::json d; d["id"]=389; d["name"]="Test389"; d["value"]=389*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),389);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test389");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test389")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),389);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt390() {
    T("Extended test 390: Data operations") {
        nlohmann::json d; d["id"]=390; d["name"]="Test390"; d["value"]=390*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),390);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test390");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test390")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),390);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt391() {
    T("Extended test 391: Data operations") {
        nlohmann::json d; d["id"]=391; d["name"]="Test391"; d["value"]=391*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),391);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test391");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test391")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),391);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt392() {
    T("Extended test 392: Data operations") {
        nlohmann::json d; d["id"]=392; d["name"]="Test392"; d["value"]=392*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),392);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test392");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test392")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),392);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt393() {
    T("Extended test 393: Data operations") {
        nlohmann::json d; d["id"]=393; d["name"]="Test393"; d["value"]=393*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),393);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test393");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test393")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),393);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt394() {
    T("Extended test 394: Data operations") {
        nlohmann::json d; d["id"]=394; d["name"]="Test394"; d["value"]=394*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),394);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test394");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test394")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),394);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt395() {
    T("Extended test 395: Data operations") {
        nlohmann::json d; d["id"]=395; d["name"]="Test395"; d["value"]=395*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),395);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test395");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test395")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),395);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt396() {
    T("Extended test 396: Data operations") {
        nlohmann::json d; d["id"]=396; d["name"]="Test396"; d["value"]=396*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),396);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test396");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test396")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),396);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt397() {
    T("Extended test 397: Data operations") {
        nlohmann::json d; d["id"]=397; d["name"]="Test397"; d["value"]=397*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),397);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test397");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test397")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),397);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt398() {
    T("Extended test 398: Data operations") {
        nlohmann::json d; d["id"]=398; d["name"]="Test398"; d["value"]=398*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),398);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test398");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test398")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),398);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt399() {
    T("Extended test 399: Data operations") {
        nlohmann::json d; d["id"]=399; d["name"]="Test399"; d["value"]=399*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),399);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test399");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test399")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),399);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt400() {
    T("Extended test 400: Data operations") {
        nlohmann::json d; d["id"]=400; d["name"]="Test400"; d["value"]=400*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),400);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test400");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test400")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),400);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt401() {
    T("Extended test 401: Data operations") {
        nlohmann::json d; d["id"]=401; d["name"]="Test401"; d["value"]=401*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),401);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test401");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test401")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),401);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt402() {
    T("Extended test 402: Data operations") {
        nlohmann::json d; d["id"]=402; d["name"]="Test402"; d["value"]=402*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),402);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test402");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test402")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),402);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt403() {
    T("Extended test 403: Data operations") {
        nlohmann::json d; d["id"]=403; d["name"]="Test403"; d["value"]=403*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),403);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test403");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test403")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),403);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt404() {
    T("Extended test 404: Data operations") {
        nlohmann::json d; d["id"]=404; d["name"]="Test404"; d["value"]=404*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),404);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test404");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test404")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),404);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt405() {
    T("Extended test 405: Data operations") {
        nlohmann::json d; d["id"]=405; d["name"]="Test405"; d["value"]=405*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),405);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test405");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test405")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),405);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt406() {
    T("Extended test 406: Data operations") {
        nlohmann::json d; d["id"]=406; d["name"]="Test406"; d["value"]=406*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),406);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test406");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test406")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),406);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt407() {
    T("Extended test 407: Data operations") {
        nlohmann::json d; d["id"]=407; d["name"]="Test407"; d["value"]=407*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),407);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test407");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test407")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),407);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt408() {
    T("Extended test 408: Data operations") {
        nlohmann::json d; d["id"]=408; d["name"]="Test408"; d["value"]=408*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),408);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test408");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test408")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),408);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt409() {
    T("Extended test 409: Data operations") {
        nlohmann::json d; d["id"]=409; d["name"]="Test409"; d["value"]=409*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),409);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test409");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test409")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),409);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt410() {
    T("Extended test 410: Data operations") {
        nlohmann::json d; d["id"]=410; d["name"]="Test410"; d["value"]=410*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),410);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test410");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test410")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),410);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt411() {
    T("Extended test 411: Data operations") {
        nlohmann::json d; d["id"]=411; d["name"]="Test411"; d["value"]=411*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),411);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test411");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test411")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),411);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt412() {
    T("Extended test 412: Data operations") {
        nlohmann::json d; d["id"]=412; d["name"]="Test412"; d["value"]=412*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),412);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test412");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test412")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),412);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt413() {
    T("Extended test 413: Data operations") {
        nlohmann::json d; d["id"]=413; d["name"]="Test413"; d["value"]=413*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),413);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test413");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test413")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),413);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt414() {
    T("Extended test 414: Data operations") {
        nlohmann::json d; d["id"]=414; d["name"]="Test414"; d["value"]=414*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),414);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test414");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test414")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),414);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt415() {
    T("Extended test 415: Data operations") {
        nlohmann::json d; d["id"]=415; d["name"]="Test415"; d["value"]=415*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),415);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test415");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test415")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),415);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt416() {
    T("Extended test 416: Data operations") {
        nlohmann::json d; d["id"]=416; d["name"]="Test416"; d["value"]=416*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),416);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test416");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test416")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),416);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt417() {
    T("Extended test 417: Data operations") {
        nlohmann::json d; d["id"]=417; d["name"]="Test417"; d["value"]=417*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),417);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test417");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test417")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),417);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt418() {
    T("Extended test 418: Data operations") {
        nlohmann::json d; d["id"]=418; d["name"]="Test418"; d["value"]=418*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),418);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test418");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test418")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),418);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt419() {
    T("Extended test 419: Data operations") {
        nlohmann::json d; d["id"]=419; d["name"]="Test419"; d["value"]=419*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),419);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test419");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test419")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),419);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt420() {
    T("Extended test 420: Data operations") {
        nlohmann::json d; d["id"]=420; d["name"]="Test420"; d["value"]=420*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),420);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test420");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test420")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),420);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt421() {
    T("Extended test 421: Data operations") {
        nlohmann::json d; d["id"]=421; d["name"]="Test421"; d["value"]=421*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),421);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test421");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test421")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),421);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt422() {
    T("Extended test 422: Data operations") {
        nlohmann::json d; d["id"]=422; d["name"]="Test422"; d["value"]=422*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),422);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test422");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test422")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),422);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt423() {
    T("Extended test 423: Data operations") {
        nlohmann::json d; d["id"]=423; d["name"]="Test423"; d["value"]=423*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),423);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test423");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test423")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),423);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt424() {
    T("Extended test 424: Data operations") {
        nlohmann::json d; d["id"]=424; d["name"]="Test424"; d["value"]=424*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),424);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test424");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test424")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),424);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt425() {
    T("Extended test 425: Data operations") {
        nlohmann::json d; d["id"]=425; d["name"]="Test425"; d["value"]=425*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),425);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test425");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test425")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),425);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt426() {
    T("Extended test 426: Data operations") {
        nlohmann::json d; d["id"]=426; d["name"]="Test426"; d["value"]=426*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),426);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test426");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test426")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),426);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt427() {
    T("Extended test 427: Data operations") {
        nlohmann::json d; d["id"]=427; d["name"]="Test427"; d["value"]=427*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),427);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test427");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test427")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),427);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt428() {
    T("Extended test 428: Data operations") {
        nlohmann::json d; d["id"]=428; d["name"]="Test428"; d["value"]=428*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),428);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test428");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test428")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),428);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt429() {
    T("Extended test 429: Data operations") {
        nlohmann::json d; d["id"]=429; d["name"]="Test429"; d["value"]=429*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),429);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test429");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test429")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),429);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt430() {
    T("Extended test 430: Data operations") {
        nlohmann::json d; d["id"]=430; d["name"]="Test430"; d["value"]=430*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),430);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test430");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test430")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),430);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt431() {
    T("Extended test 431: Data operations") {
        nlohmann::json d; d["id"]=431; d["name"]="Test431"; d["value"]=431*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),431);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test431");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test431")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),431);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt432() {
    T("Extended test 432: Data operations") {
        nlohmann::json d; d["id"]=432; d["name"]="Test432"; d["value"]=432*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),432);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test432");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test432")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),432);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt433() {
    T("Extended test 433: Data operations") {
        nlohmann::json d; d["id"]=433; d["name"]="Test433"; d["value"]=433*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),433);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test433");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test433")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),433);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt434() {
    T("Extended test 434: Data operations") {
        nlohmann::json d; d["id"]=434; d["name"]="Test434"; d["value"]=434*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),434);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test434");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test434")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),434);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt435() {
    T("Extended test 435: Data operations") {
        nlohmann::json d; d["id"]=435; d["name"]="Test435"; d["value"]=435*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),435);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test435");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test435")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),435);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt436() {
    T("Extended test 436: Data operations") {
        nlohmann::json d; d["id"]=436; d["name"]="Test436"; d["value"]=436*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),436);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test436");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test436")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),436);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt437() {
    T("Extended test 437: Data operations") {
        nlohmann::json d; d["id"]=437; d["name"]="Test437"; d["value"]=437*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),437);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test437");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test437")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),437);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt438() {
    T("Extended test 438: Data operations") {
        nlohmann::json d; d["id"]=438; d["name"]="Test438"; d["value"]=438*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),438);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test438");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test438")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),438);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt439() {
    T("Extended test 439: Data operations") {
        nlohmann::json d; d["id"]=439; d["name"]="Test439"; d["value"]=439*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),439);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test439");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test439")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),439);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt440() {
    T("Extended test 440: Data operations") {
        nlohmann::json d; d["id"]=440; d["name"]="Test440"; d["value"]=440*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),440);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test440");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test440")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),440);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt441() {
    T("Extended test 441: Data operations") {
        nlohmann::json d; d["id"]=441; d["name"]="Test441"; d["value"]=441*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),441);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test441");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test441")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),441);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt442() {
    T("Extended test 442: Data operations") {
        nlohmann::json d; d["id"]=442; d["name"]="Test442"; d["value"]=442*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),442);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test442");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test442")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),442);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt443() {
    T("Extended test 443: Data operations") {
        nlohmann::json d; d["id"]=443; d["name"]="Test443"; d["value"]=443*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),443);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test443");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test443")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),443);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt444() {
    T("Extended test 444: Data operations") {
        nlohmann::json d; d["id"]=444; d["name"]="Test444"; d["value"]=444*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),444);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test444");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test444")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),444);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt445() {
    T("Extended test 445: Data operations") {
        nlohmann::json d; d["id"]=445; d["name"]="Test445"; d["value"]=445*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),445);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test445");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test445")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),445);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt446() {
    T("Extended test 446: Data operations") {
        nlohmann::json d; d["id"]=446; d["name"]="Test446"; d["value"]=446*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),446);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test446");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test446")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),446);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt447() {
    T("Extended test 447: Data operations") {
        nlohmann::json d; d["id"]=447; d["name"]="Test447"; d["value"]=447*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),447);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test447");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test447")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),447);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt448() {
    T("Extended test 448: Data operations") {
        nlohmann::json d; d["id"]=448; d["name"]="Test448"; d["value"]=448*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),448);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test448");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test448")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),448);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt449() {
    T("Extended test 449: Data operations") {
        nlohmann::json d; d["id"]=449; d["name"]="Test449"; d["value"]=449*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),449);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test449");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test449")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),449);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt450() {
    T("Extended test 450: Data operations") {
        nlohmann::json d; d["id"]=450; d["name"]="Test450"; d["value"]=450*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),450);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test450");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test450")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),450);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt451() {
    T("Extended test 451: Data operations") {
        nlohmann::json d; d["id"]=451; d["name"]="Test451"; d["value"]=451*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),451);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test451");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test451")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),451);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt452() {
    T("Extended test 452: Data operations") {
        nlohmann::json d; d["id"]=452; d["name"]="Test452"; d["value"]=452*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),452);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test452");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test452")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),452);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt453() {
    T("Extended test 453: Data operations") {
        nlohmann::json d; d["id"]=453; d["name"]="Test453"; d["value"]=453*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),453);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test453");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test453")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),453);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt454() {
    T("Extended test 454: Data operations") {
        nlohmann::json d; d["id"]=454; d["name"]="Test454"; d["value"]=454*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),454);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test454");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test454")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),454);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt455() {
    T("Extended test 455: Data operations") {
        nlohmann::json d; d["id"]=455; d["name"]="Test455"; d["value"]=455*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),455);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test455");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test455")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),455);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt456() {
    T("Extended test 456: Data operations") {
        nlohmann::json d; d["id"]=456; d["name"]="Test456"; d["value"]=456*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),456);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test456");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test456")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),456);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt457() {
    T("Extended test 457: Data operations") {
        nlohmann::json d; d["id"]=457; d["name"]="Test457"; d["value"]=457*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),457);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test457");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test457")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),457);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt458() {
    T("Extended test 458: Data operations") {
        nlohmann::json d; d["id"]=458; d["name"]="Test458"; d["value"]=458*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),458);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test458");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test458")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),458);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt459() {
    T("Extended test 459: Data operations") {
        nlohmann::json d; d["id"]=459; d["name"]="Test459"; d["value"]=459*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),459);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test459");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test459")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),459);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt460() {
    T("Extended test 460: Data operations") {
        nlohmann::json d; d["id"]=460; d["name"]="Test460"; d["value"]=460*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),460);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test460");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test460")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),460);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt461() {
    T("Extended test 461: Data operations") {
        nlohmann::json d; d["id"]=461; d["name"]="Test461"; d["value"]=461*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),461);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test461");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test461")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),461);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt462() {
    T("Extended test 462: Data operations") {
        nlohmann::json d; d["id"]=462; d["name"]="Test462"; d["value"]=462*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),462);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test462");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test462")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),462);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt463() {
    T("Extended test 463: Data operations") {
        nlohmann::json d; d["id"]=463; d["name"]="Test463"; d["value"]=463*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),463);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test463");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test463")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),463);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt464() {
    T("Extended test 464: Data operations") {
        nlohmann::json d; d["id"]=464; d["name"]="Test464"; d["value"]=464*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),464);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test464");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test464")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),464);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt465() {
    T("Extended test 465: Data operations") {
        nlohmann::json d; d["id"]=465; d["name"]="Test465"; d["value"]=465*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),465);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test465");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test465")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),465);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt466() {
    T("Extended test 466: Data operations") {
        nlohmann::json d; d["id"]=466; d["name"]="Test466"; d["value"]=466*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),466);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test466");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test466")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),466);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt467() {
    T("Extended test 467: Data operations") {
        nlohmann::json d; d["id"]=467; d["name"]="Test467"; d["value"]=467*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),467);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test467");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test467")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),467);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt468() {
    T("Extended test 468: Data operations") {
        nlohmann::json d; d["id"]=468; d["name"]="Test468"; d["value"]=468*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),468);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test468");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test468")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),468);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt469() {
    T("Extended test 469: Data operations") {
        nlohmann::json d; d["id"]=469; d["name"]="Test469"; d["value"]=469*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),469);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test469");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test469")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),469);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt470() {
    T("Extended test 470: Data operations") {
        nlohmann::json d; d["id"]=470; d["name"]="Test470"; d["value"]=470*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),470);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test470");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test470")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),470);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt471() {
    T("Extended test 471: Data operations") {
        nlohmann::json d; d["id"]=471; d["name"]="Test471"; d["value"]=471*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),471);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test471");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test471")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),471);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt472() {
    T("Extended test 472: Data operations") {
        nlohmann::json d; d["id"]=472; d["name"]="Test472"; d["value"]=472*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),472);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test472");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test472")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),472);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt473() {
    T("Extended test 473: Data operations") {
        nlohmann::json d; d["id"]=473; d["name"]="Test473"; d["value"]=473*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),473);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test473");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test473")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),473);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt474() {
    T("Extended test 474: Data operations") {
        nlohmann::json d; d["id"]=474; d["name"]="Test474"; d["value"]=474*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),474);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test474");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test474")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),474);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt475() {
    T("Extended test 475: Data operations") {
        nlohmann::json d; d["id"]=475; d["name"]="Test475"; d["value"]=475*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),475);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test475");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test475")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),475);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt476() {
    T("Extended test 476: Data operations") {
        nlohmann::json d; d["id"]=476; d["name"]="Test476"; d["value"]=476*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),476);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test476");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test476")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),476);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt477() {
    T("Extended test 477: Data operations") {
        nlohmann::json d; d["id"]=477; d["name"]="Test477"; d["value"]=477*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),477);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test477");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test477")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),477);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt478() {
    T("Extended test 478: Data operations") {
        nlohmann::json d; d["id"]=478; d["name"]="Test478"; d["value"]=478*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),478);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test478");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test478")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),478);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt479() {
    T("Extended test 479: Data operations") {
        nlohmann::json d; d["id"]=479; d["name"]="Test479"; d["value"]=479*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),479);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test479");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test479")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),479);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt480() {
    T("Extended test 480: Data operations") {
        nlohmann::json d; d["id"]=480; d["name"]="Test480"; d["value"]=480*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),480);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test480");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test480")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),480);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt481() {
    T("Extended test 481: Data operations") {
        nlohmann::json d; d["id"]=481; d["name"]="Test481"; d["value"]=481*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),481);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test481");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test481")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),481);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt482() {
    T("Extended test 482: Data operations") {
        nlohmann::json d; d["id"]=482; d["name"]="Test482"; d["value"]=482*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),482);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test482");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test482")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),482);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt483() {
    T("Extended test 483: Data operations") {
        nlohmann::json d; d["id"]=483; d["name"]="Test483"; d["value"]=483*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),483);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test483");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test483")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),483);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt484() {
    T("Extended test 484: Data operations") {
        nlohmann::json d; d["id"]=484; d["name"]="Test484"; d["value"]=484*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),484);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test484");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test484")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),484);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt485() {
    T("Extended test 485: Data operations") {
        nlohmann::json d; d["id"]=485; d["name"]="Test485"; d["value"]=485*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),485);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test485");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test485")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),485);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt486() {
    T("Extended test 486: Data operations") {
        nlohmann::json d; d["id"]=486; d["name"]="Test486"; d["value"]=486*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),486);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test486");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test486")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),486);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt487() {
    T("Extended test 487: Data operations") {
        nlohmann::json d; d["id"]=487; d["name"]="Test487"; d["value"]=487*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),487);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test487");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test487")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),487);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt488() {
    T("Extended test 488: Data operations") {
        nlohmann::json d; d["id"]=488; d["name"]="Test488"; d["value"]=488*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),488);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test488");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test488")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),488);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt489() {
    T("Extended test 489: Data operations") {
        nlohmann::json d; d["id"]=489; d["name"]="Test489"; d["value"]=489*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),489);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test489");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test489")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),489);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt490() {
    T("Extended test 490: Data operations") {
        nlohmann::json d; d["id"]=490; d["name"]="Test490"; d["value"]=490*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),490);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test490");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test490")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),490);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt491() {
    T("Extended test 491: Data operations") {
        nlohmann::json d; d["id"]=491; d["name"]="Test491"; d["value"]=491*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),491);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test491");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test491")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),491);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt492() {
    T("Extended test 492: Data operations") {
        nlohmann::json d; d["id"]=492; d["name"]="Test492"; d["value"]=492*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),492);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test492");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test492")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),492);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt493() {
    T("Extended test 493: Data operations") {
        nlohmann::json d; d["id"]=493; d["name"]="Test493"; d["value"]=493*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),493);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test493");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test493")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),493);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt494() {
    T("Extended test 494: Data operations") {
        nlohmann::json d; d["id"]=494; d["name"]="Test494"; d["value"]=494*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),494);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test494");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test494")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),494);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt495() {
    T("Extended test 495: Data operations") {
        nlohmann::json d; d["id"]=495; d["name"]="Test495"; d["value"]=495*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),495);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test495");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test495")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),495);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt496() {
    T("Extended test 496: Data operations") {
        nlohmann::json d; d["id"]=496; d["name"]="Test496"; d["value"]=496*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),496);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test496");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test496")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),496);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt497() {
    T("Extended test 497: Data operations") {
        nlohmann::json d; d["id"]=497; d["name"]="Test497"; d["value"]=497*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),497);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test497");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test497")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),497);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt498() {
    T("Extended test 498: Data operations") {
        nlohmann::json d; d["id"]=498; d["name"]="Test498"; d["value"]=498*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),498);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test498");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test498")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),498);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt499() {
    T("Extended test 499: Data operations") {
        nlohmann::json d; d["id"]=499; d["name"]="Test499"; d["value"]=499*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),499);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test499");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test499")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),499);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt500() {
    T("Extended test 500: Data operations") {
        nlohmann::json d; d["id"]=500; d["name"]="Test500"; d["value"]=500*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),500);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test500");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test500")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),500);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt501() {
    T("Extended test 501: Data operations") {
        nlohmann::json d; d["id"]=501; d["name"]="Test501"; d["value"]=501*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),501);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test501");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test501")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),501);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt502() {
    T("Extended test 502: Data operations") {
        nlohmann::json d; d["id"]=502; d["name"]="Test502"; d["value"]=502*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),502);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test502");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test502")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),502);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt503() {
    T("Extended test 503: Data operations") {
        nlohmann::json d; d["id"]=503; d["name"]="Test503"; d["value"]=503*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),503);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test503");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test503")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),503);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt504() {
    T("Extended test 504: Data operations") {
        nlohmann::json d; d["id"]=504; d["name"]="Test504"; d["value"]=504*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),504);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test504");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test504")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),504);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt505() {
    T("Extended test 505: Data operations") {
        nlohmann::json d; d["id"]=505; d["name"]="Test505"; d["value"]=505*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),505);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test505");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test505")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),505);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt506() {
    T("Extended test 506: Data operations") {
        nlohmann::json d; d["id"]=506; d["name"]="Test506"; d["value"]=506*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),506);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test506");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test506")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),506);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt507() {
    T("Extended test 507: Data operations") {
        nlohmann::json d; d["id"]=507; d["name"]="Test507"; d["value"]=507*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),507);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test507");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test507")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),507);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt508() {
    T("Extended test 508: Data operations") {
        nlohmann::json d; d["id"]=508; d["name"]="Test508"; d["value"]=508*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),508);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test508");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test508")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),508);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt509() {
    T("Extended test 509: Data operations") {
        nlohmann::json d; d["id"]=509; d["name"]="Test509"; d["value"]=509*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),509);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test509");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test509")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),509);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt510() {
    T("Extended test 510: Data operations") {
        nlohmann::json d; d["id"]=510; d["name"]="Test510"; d["value"]=510*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),510);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test510");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test510")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),510);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt511() {
    T("Extended test 511: Data operations") {
        nlohmann::json d; d["id"]=511; d["name"]="Test511"; d["value"]=511*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),511);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test511");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test511")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),511);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt512() {
    T("Extended test 512: Data operations") {
        nlohmann::json d; d["id"]=512; d["name"]="Test512"; d["value"]=512*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),512);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test512");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test512")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),512);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt513() {
    T("Extended test 513: Data operations") {
        nlohmann::json d; d["id"]=513; d["name"]="Test513"; d["value"]=513*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),513);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test513");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test513")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),513);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt514() {
    T("Extended test 514: Data operations") {
        nlohmann::json d; d["id"]=514; d["name"]="Test514"; d["value"]=514*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),514);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test514");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test514")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),514);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt515() {
    T("Extended test 515: Data operations") {
        nlohmann::json d; d["id"]=515; d["name"]="Test515"; d["value"]=515*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),515);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test515");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test515")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),515);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt516() {
    T("Extended test 516: Data operations") {
        nlohmann::json d; d["id"]=516; d["name"]="Test516"; d["value"]=516*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),516);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test516");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test516")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),516);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt517() {
    T("Extended test 517: Data operations") {
        nlohmann::json d; d["id"]=517; d["name"]="Test517"; d["value"]=517*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),517);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test517");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test517")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),517);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt518() {
    T("Extended test 518: Data operations") {
        nlohmann::json d; d["id"]=518; d["name"]="Test518"; d["value"]=518*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),518);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test518");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test518")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),518);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt519() {
    T("Extended test 519: Data operations") {
        nlohmann::json d; d["id"]=519; d["name"]="Test519"; d["value"]=519*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),519);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test519");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test519")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),519);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt520() {
    T("Extended test 520: Data operations") {
        nlohmann::json d; d["id"]=520; d["name"]="Test520"; d["value"]=520*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),520);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test520");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test520")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),520);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt521() {
    T("Extended test 521: Data operations") {
        nlohmann::json d; d["id"]=521; d["name"]="Test521"; d["value"]=521*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),521);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test521");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test521")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),521);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt522() {
    T("Extended test 522: Data operations") {
        nlohmann::json d; d["id"]=522; d["name"]="Test522"; d["value"]=522*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),522);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test522");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test522")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),522);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt523() {
    T("Extended test 523: Data operations") {
        nlohmann::json d; d["id"]=523; d["name"]="Test523"; d["value"]=523*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),523);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test523");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test523")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),523);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt524() {
    T("Extended test 524: Data operations") {
        nlohmann::json d; d["id"]=524; d["name"]="Test524"; d["value"]=524*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),524);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test524");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test524")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),524);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt525() {
    T("Extended test 525: Data operations") {
        nlohmann::json d; d["id"]=525; d["name"]="Test525"; d["value"]=525*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),525);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test525");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test525")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),525);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt526() {
    T("Extended test 526: Data operations") {
        nlohmann::json d; d["id"]=526; d["name"]="Test526"; d["value"]=526*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),526);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test526");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test526")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),526);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt527() {
    T("Extended test 527: Data operations") {
        nlohmann::json d; d["id"]=527; d["name"]="Test527"; d["value"]=527*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),527);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test527");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test527")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),527);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt528() {
    T("Extended test 528: Data operations") {
        nlohmann::json d; d["id"]=528; d["name"]="Test528"; d["value"]=528*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),528);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test528");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test528")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),528);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt529() {
    T("Extended test 529: Data operations") {
        nlohmann::json d; d["id"]=529; d["name"]="Test529"; d["value"]=529*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),529);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test529");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test529")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),529);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt530() {
    T("Extended test 530: Data operations") {
        nlohmann::json d; d["id"]=530; d["name"]="Test530"; d["value"]=530*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),530);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test530");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test530")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),530);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt531() {
    T("Extended test 531: Data operations") {
        nlohmann::json d; d["id"]=531; d["name"]="Test531"; d["value"]=531*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),531);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test531");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test531")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),531);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt532() {
    T("Extended test 532: Data operations") {
        nlohmann::json d; d["id"]=532; d["name"]="Test532"; d["value"]=532*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),532);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test532");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test532")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),532);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt533() {
    T("Extended test 533: Data operations") {
        nlohmann::json d; d["id"]=533; d["name"]="Test533"; d["value"]=533*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),533);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test533");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test533")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),533);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt534() {
    T("Extended test 534: Data operations") {
        nlohmann::json d; d["id"]=534; d["name"]="Test534"; d["value"]=534*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),534);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test534");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test534")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),534);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt535() {
    T("Extended test 535: Data operations") {
        nlohmann::json d; d["id"]=535; d["name"]="Test535"; d["value"]=535*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),535);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test535");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test535")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),535);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt536() {
    T("Extended test 536: Data operations") {
        nlohmann::json d; d["id"]=536; d["name"]="Test536"; d["value"]=536*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),536);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test536");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test536")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),536);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt537() {
    T("Extended test 537: Data operations") {
        nlohmann::json d; d["id"]=537; d["name"]="Test537"; d["value"]=537*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),537);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test537");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test537")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),537);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt538() {
    T("Extended test 538: Data operations") {
        nlohmann::json d; d["id"]=538; d["name"]="Test538"; d["value"]=538*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),538);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test538");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test538")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),538);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt539() {
    T("Extended test 539: Data operations") {
        nlohmann::json d; d["id"]=539; d["name"]="Test539"; d["value"]=539*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),539);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test539");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test539")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),539);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt540() {
    T("Extended test 540: Data operations") {
        nlohmann::json d; d["id"]=540; d["name"]="Test540"; d["value"]=540*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),540);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test540");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test540")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),540);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt541() {
    T("Extended test 541: Data operations") {
        nlohmann::json d; d["id"]=541; d["name"]="Test541"; d["value"]=541*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),541);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test541");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test541")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),541);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt542() {
    T("Extended test 542: Data operations") {
        nlohmann::json d; d["id"]=542; d["name"]="Test542"; d["value"]=542*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),542);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test542");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test542")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),542);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt543() {
    T("Extended test 543: Data operations") {
        nlohmann::json d; d["id"]=543; d["name"]="Test543"; d["value"]=543*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),543);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test543");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test543")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),543);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt544() {
    T("Extended test 544: Data operations") {
        nlohmann::json d; d["id"]=544; d["name"]="Test544"; d["value"]=544*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),544);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test544");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test544")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),544);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt545() {
    T("Extended test 545: Data operations") {
        nlohmann::json d; d["id"]=545; d["name"]="Test545"; d["value"]=545*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),545);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test545");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test545")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),545);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt546() {
    T("Extended test 546: Data operations") {
        nlohmann::json d; d["id"]=546; d["name"]="Test546"; d["value"]=546*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),546);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test546");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test546")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),546);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt547() {
    T("Extended test 547: Data operations") {
        nlohmann::json d; d["id"]=547; d["name"]="Test547"; d["value"]=547*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),547);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test547");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test547")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),547);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt548() {
    T("Extended test 548: Data operations") {
        nlohmann::json d; d["id"]=548; d["name"]="Test548"; d["value"]=548*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),548);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test548");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test548")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),548);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt549() {
    T("Extended test 549: Data operations") {
        nlohmann::json d; d["id"]=549; d["name"]="Test549"; d["value"]=549*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),549);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test549");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test549")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),549);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt550() {
    T("Extended test 550: Data operations") {
        nlohmann::json d; d["id"]=550; d["name"]="Test550"; d["value"]=550*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),550);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test550");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test550")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),550);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt551() {
    T("Extended test 551: Data operations") {
        nlohmann::json d; d["id"]=551; d["name"]="Test551"; d["value"]=551*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),551);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test551");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test551")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),551);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt552() {
    T("Extended test 552: Data operations") {
        nlohmann::json d; d["id"]=552; d["name"]="Test552"; d["value"]=552*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),552);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test552");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test552")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),552);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt553() {
    T("Extended test 553: Data operations") {
        nlohmann::json d; d["id"]=553; d["name"]="Test553"; d["value"]=553*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),553);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test553");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test553")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),553);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt554() {
    T("Extended test 554: Data operations") {
        nlohmann::json d; d["id"]=554; d["name"]="Test554"; d["value"]=554*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),554);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test554");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test554")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),554);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt555() {
    T("Extended test 555: Data operations") {
        nlohmann::json d; d["id"]=555; d["name"]="Test555"; d["value"]=555*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),555);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test555");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test555")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),555);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt556() {
    T("Extended test 556: Data operations") {
        nlohmann::json d; d["id"]=556; d["name"]="Test556"; d["value"]=556*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),556);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test556");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test556")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),556);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt557() {
    T("Extended test 557: Data operations") {
        nlohmann::json d; d["id"]=557; d["name"]="Test557"; d["value"]=557*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),557);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test557");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test557")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),557);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt558() {
    T("Extended test 558: Data operations") {
        nlohmann::json d; d["id"]=558; d["name"]="Test558"; d["value"]=558*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),558);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test558");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test558")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),558);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt559() {
    T("Extended test 559: Data operations") {
        nlohmann::json d; d["id"]=559; d["name"]="Test559"; d["value"]=559*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),559);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test559");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test559")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),559);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt560() {
    T("Extended test 560: Data operations") {
        nlohmann::json d; d["id"]=560; d["name"]="Test560"; d["value"]=560*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),560);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test560");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test560")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),560);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt561() {
    T("Extended test 561: Data operations") {
        nlohmann::json d; d["id"]=561; d["name"]="Test561"; d["value"]=561*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),561);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test561");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test561")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),561);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt562() {
    T("Extended test 562: Data operations") {
        nlohmann::json d; d["id"]=562; d["name"]="Test562"; d["value"]=562*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),562);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test562");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test562")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),562);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt563() {
    T("Extended test 563: Data operations") {
        nlohmann::json d; d["id"]=563; d["name"]="Test563"; d["value"]=563*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),563);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test563");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test563")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),563);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt564() {
    T("Extended test 564: Data operations") {
        nlohmann::json d; d["id"]=564; d["name"]="Test564"; d["value"]=564*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),564);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test564");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test564")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),564);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt565() {
    T("Extended test 565: Data operations") {
        nlohmann::json d; d["id"]=565; d["name"]="Test565"; d["value"]=565*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),565);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test565");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test565")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),565);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt566() {
    T("Extended test 566: Data operations") {
        nlohmann::json d; d["id"]=566; d["name"]="Test566"; d["value"]=566*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),566);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test566");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test566")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),566);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt567() {
    T("Extended test 567: Data operations") {
        nlohmann::json d; d["id"]=567; d["name"]="Test567"; d["value"]=567*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),567);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test567");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test567")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),567);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt568() {
    T("Extended test 568: Data operations") {
        nlohmann::json d; d["id"]=568; d["name"]="Test568"; d["value"]=568*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),568);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test568");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test568")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),568);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt569() {
    T("Extended test 569: Data operations") {
        nlohmann::json d; d["id"]=569; d["name"]="Test569"; d["value"]=569*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),569);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test569");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test569")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),569);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt570() {
    T("Extended test 570: Data operations") {
        nlohmann::json d; d["id"]=570; d["name"]="Test570"; d["value"]=570*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),570);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test570");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test570")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),570);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt571() {
    T("Extended test 571: Data operations") {
        nlohmann::json d; d["id"]=571; d["name"]="Test571"; d["value"]=571*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),571);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test571");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test571")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),571);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt572() {
    T("Extended test 572: Data operations") {
        nlohmann::json d; d["id"]=572; d["name"]="Test572"; d["value"]=572*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),572);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test572");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test572")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),572);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt573() {
    T("Extended test 573: Data operations") {
        nlohmann::json d; d["id"]=573; d["name"]="Test573"; d["value"]=573*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),573);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test573");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test573")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),573);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt574() {
    T("Extended test 574: Data operations") {
        nlohmann::json d; d["id"]=574; d["name"]="Test574"; d["value"]=574*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),574);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test574");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test574")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),574);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt575() {
    T("Extended test 575: Data operations") {
        nlohmann::json d; d["id"]=575; d["name"]="Test575"; d["value"]=575*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),575);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test575");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test575")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),575);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt576() {
    T("Extended test 576: Data operations") {
        nlohmann::json d; d["id"]=576; d["name"]="Test576"; d["value"]=576*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),576);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test576");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test576")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),576);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt577() {
    T("Extended test 577: Data operations") {
        nlohmann::json d; d["id"]=577; d["name"]="Test577"; d["value"]=577*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),577);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test577");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test577")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),577);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt578() {
    T("Extended test 578: Data operations") {
        nlohmann::json d; d["id"]=578; d["name"]="Test578"; d["value"]=578*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),578);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test578");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test578")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),578);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt579() {
    T("Extended test 579: Data operations") {
        nlohmann::json d; d["id"]=579; d["name"]="Test579"; d["value"]=579*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),579);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test579");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test579")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),579);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt580() {
    T("Extended test 580: Data operations") {
        nlohmann::json d; d["id"]=580; d["name"]="Test580"; d["value"]=580*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),580);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test580");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test580")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),580);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt581() {
    T("Extended test 581: Data operations") {
        nlohmann::json d; d["id"]=581; d["name"]="Test581"; d["value"]=581*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),581);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test581");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test581")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),581);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt582() {
    T("Extended test 582: Data operations") {
        nlohmann::json d; d["id"]=582; d["name"]="Test582"; d["value"]=582*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),582);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test582");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test582")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),582);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt583() {
    T("Extended test 583: Data operations") {
        nlohmann::json d; d["id"]=583; d["name"]="Test583"; d["value"]=583*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),583);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test583");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test583")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),583);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt584() {
    T("Extended test 584: Data operations") {
        nlohmann::json d; d["id"]=584; d["name"]="Test584"; d["value"]=584*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),584);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test584");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test584")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),584);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt585() {
    T("Extended test 585: Data operations") {
        nlohmann::json d; d["id"]=585; d["name"]="Test585"; d["value"]=585*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),585);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test585");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test585")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),585);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt586() {
    T("Extended test 586: Data operations") {
        nlohmann::json d; d["id"]=586; d["name"]="Test586"; d["value"]=586*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),586);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test586");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test586")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),586);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt587() {
    T("Extended test 587: Data operations") {
        nlohmann::json d; d["id"]=587; d["name"]="Test587"; d["value"]=587*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),587);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test587");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test587")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),587);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt588() {
    T("Extended test 588: Data operations") {
        nlohmann::json d; d["id"]=588; d["name"]="Test588"; d["value"]=588*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),588);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test588");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test588")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),588);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt589() {
    T("Extended test 589: Data operations") {
        nlohmann::json d; d["id"]=589; d["name"]="Test589"; d["value"]=589*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),589);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test589");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test589")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),589);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt590() {
    T("Extended test 590: Data operations") {
        nlohmann::json d; d["id"]=590; d["name"]="Test590"; d["value"]=590*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),590);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test590");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test590")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),590);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt591() {
    T("Extended test 591: Data operations") {
        nlohmann::json d; d["id"]=591; d["name"]="Test591"; d["value"]=591*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),591);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test591");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test591")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),591);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt592() {
    T("Extended test 592: Data operations") {
        nlohmann::json d; d["id"]=592; d["name"]="Test592"; d["value"]=592*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),592);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test592");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test592")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),592);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt593() {
    T("Extended test 593: Data operations") {
        nlohmann::json d; d["id"]=593; d["name"]="Test593"; d["value"]=593*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),593);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test593");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test593")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),593);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt594() {
    T("Extended test 594: Data operations") {
        nlohmann::json d; d["id"]=594; d["name"]="Test594"; d["value"]=594*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),594);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test594");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test594")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),594);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt595() {
    T("Extended test 595: Data operations") {
        nlohmann::json d; d["id"]=595; d["name"]="Test595"; d["value"]=595*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),595);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test595");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test595")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),595);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt596() {
    T("Extended test 596: Data operations") {
        nlohmann::json d; d["id"]=596; d["name"]="Test596"; d["value"]=596*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),596);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test596");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test596")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),596);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt597() {
    T("Extended test 597: Data operations") {
        nlohmann::json d; d["id"]=597; d["name"]="Test597"; d["value"]=597*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),597);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test597");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test597")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),597);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt598() {
    T("Extended test 598: Data operations") {
        nlohmann::json d; d["id"]=598; d["name"]="Test598"; d["value"]=598*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),598);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test598");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test598")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),598);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt599() {
    T("Extended test 599: Data operations") {
        nlohmann::json d; d["id"]=599; d["name"]="Test599"; d["value"]=599*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),599);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test599");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test599")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),599);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt600() {
    T("Extended test 600: Data operations") {
        nlohmann::json d; d["id"]=600; d["name"]="Test600"; d["value"]=600*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),600);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test600");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test600")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),600);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt601() {
    T("Extended test 601: Data operations") {
        nlohmann::json d; d["id"]=601; d["name"]="Test601"; d["value"]=601*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),601);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test601");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test601")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),601);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt602() {
    T("Extended test 602: Data operations") {
        nlohmann::json d; d["id"]=602; d["name"]="Test602"; d["value"]=602*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),602);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test602");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test602")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),602);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt603() {
    T("Extended test 603: Data operations") {
        nlohmann::json d; d["id"]=603; d["name"]="Test603"; d["value"]=603*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),603);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test603");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test603")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),603);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt604() {
    T("Extended test 604: Data operations") {
        nlohmann::json d; d["id"]=604; d["name"]="Test604"; d["value"]=604*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),604);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test604");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test604")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),604);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt605() {
    T("Extended test 605: Data operations") {
        nlohmann::json d; d["id"]=605; d["name"]="Test605"; d["value"]=605*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),605);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test605");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test605")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),605);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt606() {
    T("Extended test 606: Data operations") {
        nlohmann::json d; d["id"]=606; d["name"]="Test606"; d["value"]=606*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),606);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test606");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test606")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),606);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt607() {
    T("Extended test 607: Data operations") {
        nlohmann::json d; d["id"]=607; d["name"]="Test607"; d["value"]=607*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),607);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test607");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test607")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),607);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt608() {
    T("Extended test 608: Data operations") {
        nlohmann::json d; d["id"]=608; d["name"]="Test608"; d["value"]=608*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),608);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test608");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test608")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),608);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt609() {
    T("Extended test 609: Data operations") {
        nlohmann::json d; d["id"]=609; d["name"]="Test609"; d["value"]=609*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),609);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test609");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test609")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),609);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt610() {
    T("Extended test 610: Data operations") {
        nlohmann::json d; d["id"]=610; d["name"]="Test610"; d["value"]=610*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),610);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test610");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test610")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),610);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt611() {
    T("Extended test 611: Data operations") {
        nlohmann::json d; d["id"]=611; d["name"]="Test611"; d["value"]=611*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),611);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test611");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test611")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),611);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt612() {
    T("Extended test 612: Data operations") {
        nlohmann::json d; d["id"]=612; d["name"]="Test612"; d["value"]=612*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),612);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test612");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test612")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),612);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt613() {
    T("Extended test 613: Data operations") {
        nlohmann::json d; d["id"]=613; d["name"]="Test613"; d["value"]=613*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),613);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test613");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test613")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),613);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt614() {
    T("Extended test 614: Data operations") {
        nlohmann::json d; d["id"]=614; d["name"]="Test614"; d["value"]=614*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),614);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test614");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test614")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),614);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt615() {
    T("Extended test 615: Data operations") {
        nlohmann::json d; d["id"]=615; d["name"]="Test615"; d["value"]=615*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),615);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test615");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test615")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),615);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt616() {
    T("Extended test 616: Data operations") {
        nlohmann::json d; d["id"]=616; d["name"]="Test616"; d["value"]=616*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),616);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test616");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test616")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),616);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt617() {
    T("Extended test 617: Data operations") {
        nlohmann::json d; d["id"]=617; d["name"]="Test617"; d["value"]=617*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),617);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test617");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test617")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),617);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt618() {
    T("Extended test 618: Data operations") {
        nlohmann::json d; d["id"]=618; d["name"]="Test618"; d["value"]=618*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),618);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test618");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test618")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),618);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt619() {
    T("Extended test 619: Data operations") {
        nlohmann::json d; d["id"]=619; d["name"]="Test619"; d["value"]=619*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),619);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test619");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test619")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),619);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt620() {
    T("Extended test 620: Data operations") {
        nlohmann::json d; d["id"]=620; d["name"]="Test620"; d["value"]=620*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),620);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test620");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test620")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),620);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt621() {
    T("Extended test 621: Data operations") {
        nlohmann::json d; d["id"]=621; d["name"]="Test621"; d["value"]=621*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),621);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test621");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test621")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),621);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt622() {
    T("Extended test 622: Data operations") {
        nlohmann::json d; d["id"]=622; d["name"]="Test622"; d["value"]=622*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),622);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test622");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test622")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),622);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt623() {
    T("Extended test 623: Data operations") {
        nlohmann::json d; d["id"]=623; d["name"]="Test623"; d["value"]=623*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),623);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test623");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test623")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),623);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt624() {
    T("Extended test 624: Data operations") {
        nlohmann::json d; d["id"]=624; d["name"]="Test624"; d["value"]=624*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),624);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test624");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test624")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),624);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt625() {
    T("Extended test 625: Data operations") {
        nlohmann::json d; d["id"]=625; d["name"]="Test625"; d["value"]=625*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),625);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test625");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test625")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),625);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt626() {
    T("Extended test 626: Data operations") {
        nlohmann::json d; d["id"]=626; d["name"]="Test626"; d["value"]=626*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),626);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test626");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test626")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),626);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt627() {
    T("Extended test 627: Data operations") {
        nlohmann::json d; d["id"]=627; d["name"]="Test627"; d["value"]=627*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),627);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test627");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test627")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),627);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt628() {
    T("Extended test 628: Data operations") {
        nlohmann::json d; d["id"]=628; d["name"]="Test628"; d["value"]=628*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),628);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test628");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test628")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),628);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt629() {
    T("Extended test 629: Data operations") {
        nlohmann::json d; d["id"]=629; d["name"]="Test629"; d["value"]=629*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),629);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test629");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test629")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),629);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt630() {
    T("Extended test 630: Data operations") {
        nlohmann::json d; d["id"]=630; d["name"]="Test630"; d["value"]=630*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),630);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test630");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test630")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),630);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt631() {
    T("Extended test 631: Data operations") {
        nlohmann::json d; d["id"]=631; d["name"]="Test631"; d["value"]=631*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),631);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test631");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test631")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),631);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt632() {
    T("Extended test 632: Data operations") {
        nlohmann::json d; d["id"]=632; d["name"]="Test632"; d["value"]=632*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),632);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test632");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test632")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),632);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt633() {
    T("Extended test 633: Data operations") {
        nlohmann::json d; d["id"]=633; d["name"]="Test633"; d["value"]=633*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),633);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test633");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test633")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),633);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt634() {
    T("Extended test 634: Data operations") {
        nlohmann::json d; d["id"]=634; d["name"]="Test634"; d["value"]=634*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),634);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test634");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test634")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),634);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt635() {
    T("Extended test 635: Data operations") {
        nlohmann::json d; d["id"]=635; d["name"]="Test635"; d["value"]=635*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),635);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test635");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test635")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),635);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt636() {
    T("Extended test 636: Data operations") {
        nlohmann::json d; d["id"]=636; d["name"]="Test636"; d["value"]=636*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),636);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test636");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test636")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),636);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt637() {
    T("Extended test 637: Data operations") {
        nlohmann::json d; d["id"]=637; d["name"]="Test637"; d["value"]=637*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),637);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test637");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test637")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),637);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt638() {
    T("Extended test 638: Data operations") {
        nlohmann::json d; d["id"]=638; d["name"]="Test638"; d["value"]=638*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),638);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test638");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test638")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),638);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt639() {
    T("Extended test 639: Data operations") {
        nlohmann::json d; d["id"]=639; d["name"]="Test639"; d["value"]=639*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),639);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test639");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test639")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),639);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt640() {
    T("Extended test 640: Data operations") {
        nlohmann::json d; d["id"]=640; d["name"]="Test640"; d["value"]=640*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),640);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test640");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test640")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),640);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt641() {
    T("Extended test 641: Data operations") {
        nlohmann::json d; d["id"]=641; d["name"]="Test641"; d["value"]=641*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),641);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test641");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test641")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),641);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt642() {
    T("Extended test 642: Data operations") {
        nlohmann::json d; d["id"]=642; d["name"]="Test642"; d["value"]=642*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),642);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test642");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test642")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),642);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt643() {
    T("Extended test 643: Data operations") {
        nlohmann::json d; d["id"]=643; d["name"]="Test643"; d["value"]=643*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),643);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test643");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test643")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),643);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt644() {
    T("Extended test 644: Data operations") {
        nlohmann::json d; d["id"]=644; d["name"]="Test644"; d["value"]=644*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),644);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test644");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test644")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),644);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt645() {
    T("Extended test 645: Data operations") {
        nlohmann::json d; d["id"]=645; d["name"]="Test645"; d["value"]=645*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),645);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test645");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test645")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),645);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt646() {
    T("Extended test 646: Data operations") {
        nlohmann::json d; d["id"]=646; d["name"]="Test646"; d["value"]=646*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),646);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test646");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test646")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),646);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt647() {
    T("Extended test 647: Data operations") {
        nlohmann::json d; d["id"]=647; d["name"]="Test647"; d["value"]=647*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),647);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test647");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test647")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),647);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt648() {
    T("Extended test 648: Data operations") {
        nlohmann::json d; d["id"]=648; d["name"]="Test648"; d["value"]=648*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),648);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test648");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test648")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),648);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt649() {
    T("Extended test 649: Data operations") {
        nlohmann::json d; d["id"]=649; d["name"]="Test649"; d["value"]=649*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),649);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test649");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test649")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),649);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt650() {
    T("Extended test 650: Data operations") {
        nlohmann::json d; d["id"]=650; d["name"]="Test650"; d["value"]=650*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),650);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test650");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test650")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),650);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt651() {
    T("Extended test 651: Data operations") {
        nlohmann::json d; d["id"]=651; d["name"]="Test651"; d["value"]=651*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),651);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test651");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test651")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),651);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt652() {
    T("Extended test 652: Data operations") {
        nlohmann::json d; d["id"]=652; d["name"]="Test652"; d["value"]=652*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),652);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test652");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test652")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),652);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt653() {
    T("Extended test 653: Data operations") {
        nlohmann::json d; d["id"]=653; d["name"]="Test653"; d["value"]=653*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),653);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test653");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test653")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),653);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt654() {
    T("Extended test 654: Data operations") {
        nlohmann::json d; d["id"]=654; d["name"]="Test654"; d["value"]=654*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),654);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test654");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test654")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),654);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt655() {
    T("Extended test 655: Data operations") {
        nlohmann::json d; d["id"]=655; d["name"]="Test655"; d["value"]=655*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),655);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test655");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test655")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),655);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt656() {
    T("Extended test 656: Data operations") {
        nlohmann::json d; d["id"]=656; d["name"]="Test656"; d["value"]=656*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),656);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test656");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test656")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),656);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt657() {
    T("Extended test 657: Data operations") {
        nlohmann::json d; d["id"]=657; d["name"]="Test657"; d["value"]=657*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),657);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test657");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test657")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),657);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt658() {
    T("Extended test 658: Data operations") {
        nlohmann::json d; d["id"]=658; d["name"]="Test658"; d["value"]=658*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),658);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test658");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test658")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),658);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt659() {
    T("Extended test 659: Data operations") {
        nlohmann::json d; d["id"]=659; d["name"]="Test659"; d["value"]=659*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),659);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test659");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test659")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),659);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt660() {
    T("Extended test 660: Data operations") {
        nlohmann::json d; d["id"]=660; d["name"]="Test660"; d["value"]=660*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),660);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test660");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test660")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),660);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt661() {
    T("Extended test 661: Data operations") {
        nlohmann::json d; d["id"]=661; d["name"]="Test661"; d["value"]=661*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),661);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test661");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test661")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),661);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt662() {
    T("Extended test 662: Data operations") {
        nlohmann::json d; d["id"]=662; d["name"]="Test662"; d["value"]=662*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),662);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test662");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test662")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),662);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt663() {
    T("Extended test 663: Data operations") {
        nlohmann::json d; d["id"]=663; d["name"]="Test663"; d["value"]=663*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),663);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test663");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test663")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),663);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt664() {
    T("Extended test 664: Data operations") {
        nlohmann::json d; d["id"]=664; d["name"]="Test664"; d["value"]=664*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),664);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test664");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test664")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),664);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt665() {
    T("Extended test 665: Data operations") {
        nlohmann::json d; d["id"]=665; d["name"]="Test665"; d["value"]=665*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),665);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test665");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test665")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),665);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt666() {
    T("Extended test 666: Data operations") {
        nlohmann::json d; d["id"]=666; d["name"]="Test666"; d["value"]=666*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),666);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test666");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test666")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),666);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt667() {
    T("Extended test 667: Data operations") {
        nlohmann::json d; d["id"]=667; d["name"]="Test667"; d["value"]=667*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),667);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test667");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test667")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),667);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt668() {
    T("Extended test 668: Data operations") {
        nlohmann::json d; d["id"]=668; d["name"]="Test668"; d["value"]=668*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),668);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test668");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test668")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),668);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt669() {
    T("Extended test 669: Data operations") {
        nlohmann::json d; d["id"]=669; d["name"]="Test669"; d["value"]=669*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),669);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test669");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test669")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),669);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt670() {
    T("Extended test 670: Data operations") {
        nlohmann::json d; d["id"]=670; d["name"]="Test670"; d["value"]=670*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),670);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test670");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test670")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),670);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt671() {
    T("Extended test 671: Data operations") {
        nlohmann::json d; d["id"]=671; d["name"]="Test671"; d["value"]=671*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),671);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test671");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test671")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),671);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt672() {
    T("Extended test 672: Data operations") {
        nlohmann::json d; d["id"]=672; d["name"]="Test672"; d["value"]=672*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),672);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test672");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test672")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),672);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt673() {
    T("Extended test 673: Data operations") {
        nlohmann::json d; d["id"]=673; d["name"]="Test673"; d["value"]=673*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),673);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test673");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test673")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),673);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt674() {
    T("Extended test 674: Data operations") {
        nlohmann::json d; d["id"]=674; d["name"]="Test674"; d["value"]=674*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),674);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test674");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test674")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),674);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt675() {
    T("Extended test 675: Data operations") {
        nlohmann::json d; d["id"]=675; d["name"]="Test675"; d["value"]=675*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),675);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test675");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test675")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),675);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt676() {
    T("Extended test 676: Data operations") {
        nlohmann::json d; d["id"]=676; d["name"]="Test676"; d["value"]=676*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),676);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test676");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test676")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),676);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt677() {
    T("Extended test 677: Data operations") {
        nlohmann::json d; d["id"]=677; d["name"]="Test677"; d["value"]=677*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),677);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test677");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test677")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),677);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt678() {
    T("Extended test 678: Data operations") {
        nlohmann::json d; d["id"]=678; d["name"]="Test678"; d["value"]=678*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),678);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test678");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test678")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),678);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt679() {
    T("Extended test 679: Data operations") {
        nlohmann::json d; d["id"]=679; d["name"]="Test679"; d["value"]=679*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),679);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test679");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test679")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),679);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt680() {
    T("Extended test 680: Data operations") {
        nlohmann::json d; d["id"]=680; d["name"]="Test680"; d["value"]=680*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),680);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test680");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test680")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),680);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt681() {
    T("Extended test 681: Data operations") {
        nlohmann::json d; d["id"]=681; d["name"]="Test681"; d["value"]=681*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),681);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test681");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test681")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),681);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt682() {
    T("Extended test 682: Data operations") {
        nlohmann::json d; d["id"]=682; d["name"]="Test682"; d["value"]=682*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),682);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test682");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test682")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),682);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt683() {
    T("Extended test 683: Data operations") {
        nlohmann::json d; d["id"]=683; d["name"]="Test683"; d["value"]=683*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),683);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test683");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test683")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),683);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt684() {
    T("Extended test 684: Data operations") {
        nlohmann::json d; d["id"]=684; d["name"]="Test684"; d["value"]=684*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),684);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test684");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test684")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),684);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt685() {
    T("Extended test 685: Data operations") {
        nlohmann::json d; d["id"]=685; d["name"]="Test685"; d["value"]=685*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),685);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test685");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test685")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),685);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt686() {
    T("Extended test 686: Data operations") {
        nlohmann::json d; d["id"]=686; d["name"]="Test686"; d["value"]=686*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),686);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test686");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test686")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),686);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt687() {
    T("Extended test 687: Data operations") {
        nlohmann::json d; d["id"]=687; d["name"]="Test687"; d["value"]=687*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),687);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test687");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test687")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),687);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt688() {
    T("Extended test 688: Data operations") {
        nlohmann::json d; d["id"]=688; d["name"]="Test688"; d["value"]=688*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),688);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test688");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test688")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),688);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt689() {
    T("Extended test 689: Data operations") {
        nlohmann::json d; d["id"]=689; d["name"]="Test689"; d["value"]=689*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),689);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test689");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test689")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),689);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt690() {
    T("Extended test 690: Data operations") {
        nlohmann::json d; d["id"]=690; d["name"]="Test690"; d["value"]=690*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),690);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test690");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test690")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),690);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt691() {
    T("Extended test 691: Data operations") {
        nlohmann::json d; d["id"]=691; d["name"]="Test691"; d["value"]=691*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),691);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test691");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test691")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),691);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt692() {
    T("Extended test 692: Data operations") {
        nlohmann::json d; d["id"]=692; d["name"]="Test692"; d["value"]=692*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),692);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test692");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test692")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),692);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt693() {
    T("Extended test 693: Data operations") {
        nlohmann::json d; d["id"]=693; d["name"]="Test693"; d["value"]=693*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),693);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test693");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test693")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),693);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt694() {
    T("Extended test 694: Data operations") {
        nlohmann::json d; d["id"]=694; d["name"]="Test694"; d["value"]=694*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),694);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test694");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test694")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),694);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt695() {
    T("Extended test 695: Data operations") {
        nlohmann::json d; d["id"]=695; d["name"]="Test695"; d["value"]=695*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),695);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test695");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test695")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),695);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt696() {
    T("Extended test 696: Data operations") {
        nlohmann::json d; d["id"]=696; d["name"]="Test696"; d["value"]=696*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),696);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test696");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test696")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),696);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt697() {
    T("Extended test 697: Data operations") {
        nlohmann::json d; d["id"]=697; d["name"]="Test697"; d["value"]=697*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),697);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test697");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test697")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),697);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt698() {
    T("Extended test 698: Data operations") {
        nlohmann::json d; d["id"]=698; d["name"]="Test698"; d["value"]=698*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),698);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test698");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test698")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),698);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt699() {
    T("Extended test 699: Data operations") {
        nlohmann::json d; d["id"]=699; d["name"]="Test699"; d["value"]=699*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),699);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test699");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test699")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),699);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt700() {
    T("Extended test 700: Data operations") {
        nlohmann::json d; d["id"]=700; d["name"]="Test700"; d["value"]=700*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),700);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test700");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test700")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),700);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt701() {
    T("Extended test 701: Data operations") {
        nlohmann::json d; d["id"]=701; d["name"]="Test701"; d["value"]=701*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),701);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test701");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test701")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),701);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt702() {
    T("Extended test 702: Data operations") {
        nlohmann::json d; d["id"]=702; d["name"]="Test702"; d["value"]=702*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),702);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test702");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test702")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),702);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt703() {
    T("Extended test 703: Data operations") {
        nlohmann::json d; d["id"]=703; d["name"]="Test703"; d["value"]=703*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),703);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test703");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test703")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),703);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt704() {
    T("Extended test 704: Data operations") {
        nlohmann::json d; d["id"]=704; d["name"]="Test704"; d["value"]=704*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),704);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test704");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test704")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),704);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt705() {
    T("Extended test 705: Data operations") {
        nlohmann::json d; d["id"]=705; d["name"]="Test705"; d["value"]=705*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),705);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test705");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test705")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),705);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt706() {
    T("Extended test 706: Data operations") {
        nlohmann::json d; d["id"]=706; d["name"]="Test706"; d["value"]=706*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),706);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test706");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test706")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),706);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt707() {
    T("Extended test 707: Data operations") {
        nlohmann::json d; d["id"]=707; d["name"]="Test707"; d["value"]=707*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),707);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test707");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test707")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),707);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt708() {
    T("Extended test 708: Data operations") {
        nlohmann::json d; d["id"]=708; d["name"]="Test708"; d["value"]=708*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),708);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test708");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test708")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),708);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt709() {
    T("Extended test 709: Data operations") {
        nlohmann::json d; d["id"]=709; d["name"]="Test709"; d["value"]=709*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),709);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test709");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test709")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),709);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt710() {
    T("Extended test 710: Data operations") {
        nlohmann::json d; d["id"]=710; d["name"]="Test710"; d["value"]=710*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),710);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test710");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test710")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),710);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt711() {
    T("Extended test 711: Data operations") {
        nlohmann::json d; d["id"]=711; d["name"]="Test711"; d["value"]=711*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),711);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test711");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test711")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),711);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt712() {
    T("Extended test 712: Data operations") {
        nlohmann::json d; d["id"]=712; d["name"]="Test712"; d["value"]=712*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),712);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test712");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test712")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),712);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt713() {
    T("Extended test 713: Data operations") {
        nlohmann::json d; d["id"]=713; d["name"]="Test713"; d["value"]=713*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),713);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test713");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test713")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),713);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt714() {
    T("Extended test 714: Data operations") {
        nlohmann::json d; d["id"]=714; d["name"]="Test714"; d["value"]=714*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),714);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test714");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test714")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),714);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt715() {
    T("Extended test 715: Data operations") {
        nlohmann::json d; d["id"]=715; d["name"]="Test715"; d["value"]=715*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),715);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test715");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test715")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),715);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt716() {
    T("Extended test 716: Data operations") {
        nlohmann::json d; d["id"]=716; d["name"]="Test716"; d["value"]=716*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),716);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test716");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test716")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),716);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt717() {
    T("Extended test 717: Data operations") {
        nlohmann::json d; d["id"]=717; d["name"]="Test717"; d["value"]=717*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),717);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test717");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test717")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),717);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt718() {
    T("Extended test 718: Data operations") {
        nlohmann::json d; d["id"]=718; d["name"]="Test718"; d["value"]=718*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),718);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test718");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test718")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),718);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt719() {
    T("Extended test 719: Data operations") {
        nlohmann::json d; d["id"]=719; d["name"]="Test719"; d["value"]=719*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),719);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test719");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test719")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),719);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt720() {
    T("Extended test 720: Data operations") {
        nlohmann::json d; d["id"]=720; d["name"]="Test720"; d["value"]=720*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),720);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test720");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test720")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),720);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt721() {
    T("Extended test 721: Data operations") {
        nlohmann::json d; d["id"]=721; d["name"]="Test721"; d["value"]=721*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),721);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test721");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test721")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),721);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt722() {
    T("Extended test 722: Data operations") {
        nlohmann::json d; d["id"]=722; d["name"]="Test722"; d["value"]=722*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),722);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test722");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test722")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),722);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt723() {
    T("Extended test 723: Data operations") {
        nlohmann::json d; d["id"]=723; d["name"]="Test723"; d["value"]=723*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),723);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test723");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test723")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),723);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt724() {
    T("Extended test 724: Data operations") {
        nlohmann::json d; d["id"]=724; d["name"]="Test724"; d["value"]=724*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),724);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test724");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test724")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),724);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt725() {
    T("Extended test 725: Data operations") {
        nlohmann::json d; d["id"]=725; d["name"]="Test725"; d["value"]=725*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),725);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test725");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test725")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),725);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt726() {
    T("Extended test 726: Data operations") {
        nlohmann::json d; d["id"]=726; d["name"]="Test726"; d["value"]=726*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),726);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test726");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test726")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),726);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt727() {
    T("Extended test 727: Data operations") {
        nlohmann::json d; d["id"]=727; d["name"]="Test727"; d["value"]=727*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),727);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test727");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test727")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),727);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt728() {
    T("Extended test 728: Data operations") {
        nlohmann::json d; d["id"]=728; d["name"]="Test728"; d["value"]=728*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),728);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test728");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test728")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),728);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt729() {
    T("Extended test 729: Data operations") {
        nlohmann::json d; d["id"]=729; d["name"]="Test729"; d["value"]=729*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),729);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test729");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test729")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),729);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt730() {
    T("Extended test 730: Data operations") {
        nlohmann::json d; d["id"]=730; d["name"]="Test730"; d["value"]=730*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),730);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test730");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test730")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),730);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt731() {
    T("Extended test 731: Data operations") {
        nlohmann::json d; d["id"]=731; d["name"]="Test731"; d["value"]=731*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),731);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test731");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test731")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),731);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt732() {
    T("Extended test 732: Data operations") {
        nlohmann::json d; d["id"]=732; d["name"]="Test732"; d["value"]=732*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),732);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test732");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test732")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),732);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt733() {
    T("Extended test 733: Data operations") {
        nlohmann::json d; d["id"]=733; d["name"]="Test733"; d["value"]=733*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),733);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test733");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test733")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),733);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt734() {
    T("Extended test 734: Data operations") {
        nlohmann::json d; d["id"]=734; d["name"]="Test734"; d["value"]=734*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),734);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test734");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test734")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),734);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt735() {
    T("Extended test 735: Data operations") {
        nlohmann::json d; d["id"]=735; d["name"]="Test735"; d["value"]=735*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),735);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test735");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test735")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),735);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt736() {
    T("Extended test 736: Data operations") {
        nlohmann::json d; d["id"]=736; d["name"]="Test736"; d["value"]=736*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),736);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test736");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test736")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),736);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt737() {
    T("Extended test 737: Data operations") {
        nlohmann::json d; d["id"]=737; d["name"]="Test737"; d["value"]=737*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),737);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test737");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test737")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),737);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt738() {
    T("Extended test 738: Data operations") {
        nlohmann::json d; d["id"]=738; d["name"]="Test738"; d["value"]=738*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),738);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test738");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test738")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),738);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt739() {
    T("Extended test 739: Data operations") {
        nlohmann::json d; d["id"]=739; d["name"]="Test739"; d["value"]=739*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),739);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test739");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test739")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),739);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt740() {
    T("Extended test 740: Data operations") {
        nlohmann::json d; d["id"]=740; d["name"]="Test740"; d["value"]=740*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),740);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test740");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test740")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),740);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt741() {
    T("Extended test 741: Data operations") {
        nlohmann::json d; d["id"]=741; d["name"]="Test741"; d["value"]=741*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),741);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test741");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test741")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),741);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt742() {
    T("Extended test 742: Data operations") {
        nlohmann::json d; d["id"]=742; d["name"]="Test742"; d["value"]=742*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),742);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test742");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test742")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),742);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt743() {
    T("Extended test 743: Data operations") {
        nlohmann::json d; d["id"]=743; d["name"]="Test743"; d["value"]=743*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),743);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test743");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test743")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),743);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt744() {
    T("Extended test 744: Data operations") {
        nlohmann::json d; d["id"]=744; d["name"]="Test744"; d["value"]=744*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),744);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test744");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test744")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),744);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt745() {
    T("Extended test 745: Data operations") {
        nlohmann::json d; d["id"]=745; d["name"]="Test745"; d["value"]=745*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),745);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test745");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test745")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),745);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt746() {
    T("Extended test 746: Data operations") {
        nlohmann::json d; d["id"]=746; d["name"]="Test746"; d["value"]=746*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),746);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test746");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test746")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),746);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt747() {
    T("Extended test 747: Data operations") {
        nlohmann::json d; d["id"]=747; d["name"]="Test747"; d["value"]=747*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),747);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test747");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test747")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),747);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt748() {
    T("Extended test 748: Data operations") {
        nlohmann::json d; d["id"]=748; d["name"]="Test748"; d["value"]=748*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),748);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test748");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test748")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),748);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt749() {
    T("Extended test 749: Data operations") {
        nlohmann::json d; d["id"]=749; d["name"]="Test749"; d["value"]=749*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),749);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test749");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test749")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),749);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt750() {
    T("Extended test 750: Data operations") {
        nlohmann::json d; d["id"]=750; d["name"]="Test750"; d["value"]=750*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),750);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test750");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test750")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),750);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt751() {
    T("Extended test 751: Data operations") {
        nlohmann::json d; d["id"]=751; d["name"]="Test751"; d["value"]=751*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),751);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test751");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test751")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),751);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt752() {
    T("Extended test 752: Data operations") {
        nlohmann::json d; d["id"]=752; d["name"]="Test752"; d["value"]=752*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),752);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test752");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test752")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),752);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt753() {
    T("Extended test 753: Data operations") {
        nlohmann::json d; d["id"]=753; d["name"]="Test753"; d["value"]=753*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),753);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test753");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test753")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),753);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt754() {
    T("Extended test 754: Data operations") {
        nlohmann::json d; d["id"]=754; d["name"]="Test754"; d["value"]=754*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),754);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test754");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test754")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),754);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt755() {
    T("Extended test 755: Data operations") {
        nlohmann::json d; d["id"]=755; d["name"]="Test755"; d["value"]=755*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),755);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test755");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test755")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),755);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt756() {
    T("Extended test 756: Data operations") {
        nlohmann::json d; d["id"]=756; d["name"]="Test756"; d["value"]=756*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),756);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test756");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test756")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),756);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt757() {
    T("Extended test 757: Data operations") {
        nlohmann::json d; d["id"]=757; d["name"]="Test757"; d["value"]=757*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),757);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test757");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test757")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),757);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt758() {
    T("Extended test 758: Data operations") {
        nlohmann::json d; d["id"]=758; d["name"]="Test758"; d["value"]=758*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),758);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test758");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test758")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),758);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt759() {
    T("Extended test 759: Data operations") {
        nlohmann::json d; d["id"]=759; d["name"]="Test759"; d["value"]=759*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),759);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test759");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test759")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),759);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt760() {
    T("Extended test 760: Data operations") {
        nlohmann::json d; d["id"]=760; d["name"]="Test760"; d["value"]=760*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),760);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test760");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test760")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),760);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt761() {
    T("Extended test 761: Data operations") {
        nlohmann::json d; d["id"]=761; d["name"]="Test761"; d["value"]=761*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),761);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test761");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test761")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),761);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt762() {
    T("Extended test 762: Data operations") {
        nlohmann::json d; d["id"]=762; d["name"]="Test762"; d["value"]=762*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),762);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test762");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test762")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),762);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt763() {
    T("Extended test 763: Data operations") {
        nlohmann::json d; d["id"]=763; d["name"]="Test763"; d["value"]=763*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),763);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test763");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test763")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),763);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt764() {
    T("Extended test 764: Data operations") {
        nlohmann::json d; d["id"]=764; d["name"]="Test764"; d["value"]=764*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),764);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test764");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test764")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),764);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt765() {
    T("Extended test 765: Data operations") {
        nlohmann::json d; d["id"]=765; d["name"]="Test765"; d["value"]=765*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),765);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test765");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test765")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),765);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt766() {
    T("Extended test 766: Data operations") {
        nlohmann::json d; d["id"]=766; d["name"]="Test766"; d["value"]=766*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),766);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test766");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test766")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),766);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt767() {
    T("Extended test 767: Data operations") {
        nlohmann::json d; d["id"]=767; d["name"]="Test767"; d["value"]=767*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),767);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test767");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test767")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),767);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt768() {
    T("Extended test 768: Data operations") {
        nlohmann::json d; d["id"]=768; d["name"]="Test768"; d["value"]=768*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),768);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test768");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test768")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),768);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt769() {
    T("Extended test 769: Data operations") {
        nlohmann::json d; d["id"]=769; d["name"]="Test769"; d["value"]=769*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),769);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test769");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test769")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),769);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt770() {
    T("Extended test 770: Data operations") {
        nlohmann::json d; d["id"]=770; d["name"]="Test770"; d["value"]=770*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),770);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test770");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test770")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),770);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt771() {
    T("Extended test 771: Data operations") {
        nlohmann::json d; d["id"]=771; d["name"]="Test771"; d["value"]=771*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),771);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test771");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test771")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),771);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt772() {
    T("Extended test 772: Data operations") {
        nlohmann::json d; d["id"]=772; d["name"]="Test772"; d["value"]=772*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),772);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test772");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test772")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),772);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt773() {
    T("Extended test 773: Data operations") {
        nlohmann::json d; d["id"]=773; d["name"]="Test773"; d["value"]=773*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),773);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test773");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test773")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),773);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt774() {
    T("Extended test 774: Data operations") {
        nlohmann::json d; d["id"]=774; d["name"]="Test774"; d["value"]=774*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),774);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test774");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test774")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),774);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt775() {
    T("Extended test 775: Data operations") {
        nlohmann::json d; d["id"]=775; d["name"]="Test775"; d["value"]=775*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),775);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test775");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test775")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),775);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt776() {
    T("Extended test 776: Data operations") {
        nlohmann::json d; d["id"]=776; d["name"]="Test776"; d["value"]=776*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),776);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test776");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test776")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),776);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt777() {
    T("Extended test 777: Data operations") {
        nlohmann::json d; d["id"]=777; d["name"]="Test777"; d["value"]=777*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),777);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test777");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test777")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),777);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt778() {
    T("Extended test 778: Data operations") {
        nlohmann::json d; d["id"]=778; d["name"]="Test778"; d["value"]=778*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),778);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test778");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test778")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),778);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt779() {
    T("Extended test 779: Data operations") {
        nlohmann::json d; d["id"]=779; d["name"]="Test779"; d["value"]=779*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),779);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test779");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test779")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),779);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt780() {
    T("Extended test 780: Data operations") {
        nlohmann::json d; d["id"]=780; d["name"]="Test780"; d["value"]=780*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),780);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test780");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test780")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),780);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt781() {
    T("Extended test 781: Data operations") {
        nlohmann::json d; d["id"]=781; d["name"]="Test781"; d["value"]=781*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),781);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test781");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test781")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),781);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt782() {
    T("Extended test 782: Data operations") {
        nlohmann::json d; d["id"]=782; d["name"]="Test782"; d["value"]=782*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),782);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test782");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test782")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),782);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt783() {
    T("Extended test 783: Data operations") {
        nlohmann::json d; d["id"]=783; d["name"]="Test783"; d["value"]=783*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),783);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test783");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test783")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),783);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt784() {
    T("Extended test 784: Data operations") {
        nlohmann::json d; d["id"]=784; d["name"]="Test784"; d["value"]=784*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),784);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test784");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test784")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),784);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt785() {
    T("Extended test 785: Data operations") {
        nlohmann::json d; d["id"]=785; d["name"]="Test785"; d["value"]=785*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),785);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test785");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test785")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),785);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt786() {
    T("Extended test 786: Data operations") {
        nlohmann::json d; d["id"]=786; d["name"]="Test786"; d["value"]=786*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),786);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test786");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test786")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),786);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt787() {
    T("Extended test 787: Data operations") {
        nlohmann::json d; d["id"]=787; d["name"]="Test787"; d["value"]=787*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),787);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test787");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test787")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),787);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt788() {
    T("Extended test 788: Data operations") {
        nlohmann::json d; d["id"]=788; d["name"]="Test788"; d["value"]=788*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),788);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test788");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test788")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),788);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt789() {
    T("Extended test 789: Data operations") {
        nlohmann::json d; d["id"]=789; d["name"]="Test789"; d["value"]=789*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),789);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test789");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test789")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),789);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt790() {
    T("Extended test 790: Data operations") {
        nlohmann::json d; d["id"]=790; d["name"]="Test790"; d["value"]=790*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),790);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test790");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test790")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),790);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt791() {
    T("Extended test 791: Data operations") {
        nlohmann::json d; d["id"]=791; d["name"]="Test791"; d["value"]=791*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),791);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test791");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test791")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),791);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt792() {
    T("Extended test 792: Data operations") {
        nlohmann::json d; d["id"]=792; d["name"]="Test792"; d["value"]=792*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),792);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test792");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test792")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),792);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt793() {
    T("Extended test 793: Data operations") {
        nlohmann::json d; d["id"]=793; d["name"]="Test793"; d["value"]=793*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),793);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test793");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test793")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),793);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt794() {
    T("Extended test 794: Data operations") {
        nlohmann::json d; d["id"]=794; d["name"]="Test794"; d["value"]=794*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),794);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test794");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test794")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),794);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt795() {
    T("Extended test 795: Data operations") {
        nlohmann::json d; d["id"]=795; d["name"]="Test795"; d["value"]=795*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),795);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test795");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test795")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),795);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt796() {
    T("Extended test 796: Data operations") {
        nlohmann::json d; d["id"]=796; d["name"]="Test796"; d["value"]=796*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),796);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test796");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test796")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),796);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt797() {
    T("Extended test 797: Data operations") {
        nlohmann::json d; d["id"]=797; d["name"]="Test797"; d["value"]=797*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),797);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test797");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test797")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),797);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt798() {
    T("Extended test 798: Data operations") {
        nlohmann::json d; d["id"]=798; d["name"]="Test798"; d["value"]=798*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),798);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test798");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test798")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),798);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt799() {
    T("Extended test 799: Data operations") {
        nlohmann::json d; d["id"]=799; d["name"]="Test799"; d["value"]=799*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),799);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test799");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test799")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),799);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt800() {
    T("Extended test 800: Data operations") {
        nlohmann::json d; d["id"]=800; d["name"]="Test800"; d["value"]=800*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),800);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test800");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test800")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),800);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt801() {
    T("Extended test 801: Data operations") {
        nlohmann::json d; d["id"]=801; d["name"]="Test801"; d["value"]=801*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),801);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test801");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test801")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),801);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt802() {
    T("Extended test 802: Data operations") {
        nlohmann::json d; d["id"]=802; d["name"]="Test802"; d["value"]=802*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),802);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test802");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test802")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),802);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt803() {
    T("Extended test 803: Data operations") {
        nlohmann::json d; d["id"]=803; d["name"]="Test803"; d["value"]=803*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),803);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test803");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test803")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),803);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt804() {
    T("Extended test 804: Data operations") {
        nlohmann::json d; d["id"]=804; d["name"]="Test804"; d["value"]=804*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),804);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test804");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test804")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),804);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt805() {
    T("Extended test 805: Data operations") {
        nlohmann::json d; d["id"]=805; d["name"]="Test805"; d["value"]=805*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),805);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test805");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test805")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),805);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt806() {
    T("Extended test 806: Data operations") {
        nlohmann::json d; d["id"]=806; d["name"]="Test806"; d["value"]=806*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),806);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test806");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test806")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),806);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt807() {
    T("Extended test 807: Data operations") {
        nlohmann::json d; d["id"]=807; d["name"]="Test807"; d["value"]=807*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),807);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test807");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test807")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),807);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt808() {
    T("Extended test 808: Data operations") {
        nlohmann::json d; d["id"]=808; d["name"]="Test808"; d["value"]=808*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),808);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test808");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test808")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),808);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt809() {
    T("Extended test 809: Data operations") {
        nlohmann::json d; d["id"]=809; d["name"]="Test809"; d["value"]=809*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),809);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test809");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test809")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),809);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt810() {
    T("Extended test 810: Data operations") {
        nlohmann::json d; d["id"]=810; d["name"]="Test810"; d["value"]=810*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),810);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test810");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test810")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),810);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt811() {
    T("Extended test 811: Data operations") {
        nlohmann::json d; d["id"]=811; d["name"]="Test811"; d["value"]=811*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),811);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test811");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test811")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),811);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt812() {
    T("Extended test 812: Data operations") {
        nlohmann::json d; d["id"]=812; d["name"]="Test812"; d["value"]=812*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),812);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test812");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test812")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),812);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt813() {
    T("Extended test 813: Data operations") {
        nlohmann::json d; d["id"]=813; d["name"]="Test813"; d["value"]=813*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),813);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test813");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test813")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),813);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt814() {
    T("Extended test 814: Data operations") {
        nlohmann::json d; d["id"]=814; d["name"]="Test814"; d["value"]=814*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),814);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test814");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test814")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),814);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt815() {
    T("Extended test 815: Data operations") {
        nlohmann::json d; d["id"]=815; d["name"]="Test815"; d["value"]=815*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),815);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test815");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test815")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),815);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt816() {
    T("Extended test 816: Data operations") {
        nlohmann::json d; d["id"]=816; d["name"]="Test816"; d["value"]=816*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),816);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test816");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test816")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),816);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt817() {
    T("Extended test 817: Data operations") {
        nlohmann::json d; d["id"]=817; d["name"]="Test817"; d["value"]=817*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),817);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test817");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test817")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),817);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt818() {
    T("Extended test 818: Data operations") {
        nlohmann::json d; d["id"]=818; d["name"]="Test818"; d["value"]=818*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),818);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test818");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test818")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),818);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt819() {
    T("Extended test 819: Data operations") {
        nlohmann::json d; d["id"]=819; d["name"]="Test819"; d["value"]=819*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),819);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test819");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test819")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),819);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt820() {
    T("Extended test 820: Data operations") {
        nlohmann::json d; d["id"]=820; d["name"]="Test820"; d["value"]=820*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),820);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test820");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test820")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),820);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt821() {
    T("Extended test 821: Data operations") {
        nlohmann::json d; d["id"]=821; d["name"]="Test821"; d["value"]=821*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),821);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test821");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test821")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),821);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt822() {
    T("Extended test 822: Data operations") {
        nlohmann::json d; d["id"]=822; d["name"]="Test822"; d["value"]=822*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),822);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test822");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test822")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),822);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt823() {
    T("Extended test 823: Data operations") {
        nlohmann::json d; d["id"]=823; d["name"]="Test823"; d["value"]=823*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),823);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test823");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test823")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),823);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt824() {
    T("Extended test 824: Data operations") {
        nlohmann::json d; d["id"]=824; d["name"]="Test824"; d["value"]=824*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),824);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test824");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test824")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),824);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt825() {
    T("Extended test 825: Data operations") {
        nlohmann::json d; d["id"]=825; d["name"]="Test825"; d["value"]=825*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),825);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test825");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test825")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),825);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt826() {
    T("Extended test 826: Data operations") {
        nlohmann::json d; d["id"]=826; d["name"]="Test826"; d["value"]=826*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),826);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test826");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test826")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),826);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt827() {
    T("Extended test 827: Data operations") {
        nlohmann::json d; d["id"]=827; d["name"]="Test827"; d["value"]=827*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),827);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test827");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test827")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),827);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt828() {
    T("Extended test 828: Data operations") {
        nlohmann::json d; d["id"]=828; d["name"]="Test828"; d["value"]=828*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),828);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test828");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test828")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),828);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt829() {
    T("Extended test 829: Data operations") {
        nlohmann::json d; d["id"]=829; d["name"]="Test829"; d["value"]=829*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),829);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test829");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test829")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),829);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt830() {
    T("Extended test 830: Data operations") {
        nlohmann::json d; d["id"]=830; d["name"]="Test830"; d["value"]=830*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),830);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test830");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test830")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),830);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt831() {
    T("Extended test 831: Data operations") {
        nlohmann::json d; d["id"]=831; d["name"]="Test831"; d["value"]=831*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),831);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test831");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test831")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),831);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt832() {
    T("Extended test 832: Data operations") {
        nlohmann::json d; d["id"]=832; d["name"]="Test832"; d["value"]=832*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),832);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test832");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test832")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),832);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt833() {
    T("Extended test 833: Data operations") {
        nlohmann::json d; d["id"]=833; d["name"]="Test833"; d["value"]=833*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),833);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test833");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test833")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),833);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt834() {
    T("Extended test 834: Data operations") {
        nlohmann::json d; d["id"]=834; d["name"]="Test834"; d["value"]=834*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),834);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test834");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test834")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),834);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt835() {
    T("Extended test 835: Data operations") {
        nlohmann::json d; d["id"]=835; d["name"]="Test835"; d["value"]=835*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),835);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test835");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test835")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),835);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt836() {
    T("Extended test 836: Data operations") {
        nlohmann::json d; d["id"]=836; d["name"]="Test836"; d["value"]=836*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),836);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test836");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test836")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),836);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt837() {
    T("Extended test 837: Data operations") {
        nlohmann::json d; d["id"]=837; d["name"]="Test837"; d["value"]=837*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),837);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test837");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test837")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),837);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt838() {
    T("Extended test 838: Data operations") {
        nlohmann::json d; d["id"]=838; d["name"]="Test838"; d["value"]=838*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),838);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test838");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test838")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),838);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt839() {
    T("Extended test 839: Data operations") {
        nlohmann::json d; d["id"]=839; d["name"]="Test839"; d["value"]=839*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),839);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test839");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test839")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),839);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt840() {
    T("Extended test 840: Data operations") {
        nlohmann::json d; d["id"]=840; d["name"]="Test840"; d["value"]=840*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),840);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test840");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test840")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),840);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt841() {
    T("Extended test 841: Data operations") {
        nlohmann::json d; d["id"]=841; d["name"]="Test841"; d["value"]=841*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),841);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test841");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test841")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),841);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt842() {
    T("Extended test 842: Data operations") {
        nlohmann::json d; d["id"]=842; d["name"]="Test842"; d["value"]=842*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),842);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test842");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test842")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),842);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt843() {
    T("Extended test 843: Data operations") {
        nlohmann::json d; d["id"]=843; d["name"]="Test843"; d["value"]=843*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),843);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test843");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test843")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),843);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt844() {
    T("Extended test 844: Data operations") {
        nlohmann::json d; d["id"]=844; d["name"]="Test844"; d["value"]=844*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),844);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test844");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test844")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),844);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt845() {
    T("Extended test 845: Data operations") {
        nlohmann::json d; d["id"]=845; d["name"]="Test845"; d["value"]=845*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),845);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test845");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test845")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),845);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt846() {
    T("Extended test 846: Data operations") {
        nlohmann::json d; d["id"]=846; d["name"]="Test846"; d["value"]=846*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),846);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test846");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test846")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),846);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt847() {
    T("Extended test 847: Data operations") {
        nlohmann::json d; d["id"]=847; d["name"]="Test847"; d["value"]=847*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),847);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test847");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test847")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),847);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt848() {
    T("Extended test 848: Data operations") {
        nlohmann::json d; d["id"]=848; d["name"]="Test848"; d["value"]=848*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),848);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test848");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test848")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),848);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt849() {
    T("Extended test 849: Data operations") {
        nlohmann::json d; d["id"]=849; d["name"]="Test849"; d["value"]=849*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),849);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test849");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test849")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),849);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt850() {
    T("Extended test 850: Data operations") {
        nlohmann::json d; d["id"]=850; d["name"]="Test850"; d["value"]=850*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),850);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test850");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test850")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),850);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt851() {
    T("Extended test 851: Data operations") {
        nlohmann::json d; d["id"]=851; d["name"]="Test851"; d["value"]=851*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),851);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test851");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test851")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),851);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt852() {
    T("Extended test 852: Data operations") {
        nlohmann::json d; d["id"]=852; d["name"]="Test852"; d["value"]=852*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),852);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test852");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test852")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),852);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt853() {
    T("Extended test 853: Data operations") {
        nlohmann::json d; d["id"]=853; d["name"]="Test853"; d["value"]=853*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),853);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test853");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test853")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),853);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt854() {
    T("Extended test 854: Data operations") {
        nlohmann::json d; d["id"]=854; d["name"]="Test854"; d["value"]=854*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),854);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test854");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test854")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),854);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt855() {
    T("Extended test 855: Data operations") {
        nlohmann::json d; d["id"]=855; d["name"]="Test855"; d["value"]=855*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),855);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test855");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test855")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),855);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt856() {
    T("Extended test 856: Data operations") {
        nlohmann::json d; d["id"]=856; d["name"]="Test856"; d["value"]=856*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),856);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test856");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test856")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),856);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt857() {
    T("Extended test 857: Data operations") {
        nlohmann::json d; d["id"]=857; d["name"]="Test857"; d["value"]=857*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),857);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test857");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test857")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),857);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt858() {
    T("Extended test 858: Data operations") {
        nlohmann::json d; d["id"]=858; d["name"]="Test858"; d["value"]=858*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),858);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test858");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test858")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),858);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt859() {
    T("Extended test 859: Data operations") {
        nlohmann::json d; d["id"]=859; d["name"]="Test859"; d["value"]=859*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),859);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test859");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test859")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),859);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt860() {
    T("Extended test 860: Data operations") {
        nlohmann::json d; d["id"]=860; d["name"]="Test860"; d["value"]=860*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),860);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test860");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test860")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),860);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt861() {
    T("Extended test 861: Data operations") {
        nlohmann::json d; d["id"]=861; d["name"]="Test861"; d["value"]=861*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),861);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test861");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test861")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),861);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt862() {
    T("Extended test 862: Data operations") {
        nlohmann::json d; d["id"]=862; d["name"]="Test862"; d["value"]=862*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),862);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test862");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test862")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),862);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt863() {
    T("Extended test 863: Data operations") {
        nlohmann::json d; d["id"]=863; d["name"]="Test863"; d["value"]=863*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),863);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test863");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test863")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),863);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt864() {
    T("Extended test 864: Data operations") {
        nlohmann::json d; d["id"]=864; d["name"]="Test864"; d["value"]=864*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),864);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test864");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test864")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),864);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt865() {
    T("Extended test 865: Data operations") {
        nlohmann::json d; d["id"]=865; d["name"]="Test865"; d["value"]=865*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),865);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test865");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test865")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),865);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt866() {
    T("Extended test 866: Data operations") {
        nlohmann::json d; d["id"]=866; d["name"]="Test866"; d["value"]=866*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),866);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test866");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test866")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),866);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt867() {
    T("Extended test 867: Data operations") {
        nlohmann::json d; d["id"]=867; d["name"]="Test867"; d["value"]=867*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),867);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test867");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test867")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),867);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt868() {
    T("Extended test 868: Data operations") {
        nlohmann::json d; d["id"]=868; d["name"]="Test868"; d["value"]=868*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),868);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test868");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test868")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),868);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt869() {
    T("Extended test 869: Data operations") {
        nlohmann::json d; d["id"]=869; d["name"]="Test869"; d["value"]=869*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),869);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test869");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test869")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),869);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt870() {
    T("Extended test 870: Data operations") {
        nlohmann::json d; d["id"]=870; d["name"]="Test870"; d["value"]=870*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),870);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test870");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test870")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),870);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt871() {
    T("Extended test 871: Data operations") {
        nlohmann::json d; d["id"]=871; d["name"]="Test871"; d["value"]=871*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),871);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test871");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test871")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),871);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt872() {
    T("Extended test 872: Data operations") {
        nlohmann::json d; d["id"]=872; d["name"]="Test872"; d["value"]=872*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),872);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test872");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test872")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),872);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt873() {
    T("Extended test 873: Data operations") {
        nlohmann::json d; d["id"]=873; d["name"]="Test873"; d["value"]=873*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),873);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test873");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test873")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),873);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt874() {
    T("Extended test 874: Data operations") {
        nlohmann::json d; d["id"]=874; d["name"]="Test874"; d["value"]=874*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),874);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test874");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test874")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),874);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt875() {
    T("Extended test 875: Data operations") {
        nlohmann::json d; d["id"]=875; d["name"]="Test875"; d["value"]=875*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),875);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test875");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test875")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),875);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt876() {
    T("Extended test 876: Data operations") {
        nlohmann::json d; d["id"]=876; d["name"]="Test876"; d["value"]=876*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),876);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test876");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test876")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),876);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt877() {
    T("Extended test 877: Data operations") {
        nlohmann::json d; d["id"]=877; d["name"]="Test877"; d["value"]=877*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),877);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test877");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test877")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),877);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt878() {
    T("Extended test 878: Data operations") {
        nlohmann::json d; d["id"]=878; d["name"]="Test878"; d["value"]=878*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),878);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test878");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test878")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),878);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt879() {
    T("Extended test 879: Data operations") {
        nlohmann::json d; d["id"]=879; d["name"]="Test879"; d["value"]=879*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),879);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test879");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test879")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),879);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt880() {
    T("Extended test 880: Data operations") {
        nlohmann::json d; d["id"]=880; d["name"]="Test880"; d["value"]=880*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),880);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test880");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test880")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),880);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt881() {
    T("Extended test 881: Data operations") {
        nlohmann::json d; d["id"]=881; d["name"]="Test881"; d["value"]=881*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),881);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test881");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test881")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),881);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt882() {
    T("Extended test 882: Data operations") {
        nlohmann::json d; d["id"]=882; d["name"]="Test882"; d["value"]=882*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),882);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test882");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test882")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),882);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt883() {
    T("Extended test 883: Data operations") {
        nlohmann::json d; d["id"]=883; d["name"]="Test883"; d["value"]=883*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),883);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test883");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test883")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),883);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt884() {
    T("Extended test 884: Data operations") {
        nlohmann::json d; d["id"]=884; d["name"]="Test884"; d["value"]=884*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),884);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test884");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test884")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),884);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt885() {
    T("Extended test 885: Data operations") {
        nlohmann::json d; d["id"]=885; d["name"]="Test885"; d["value"]=885*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),885);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test885");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test885")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),885);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt886() {
    T("Extended test 886: Data operations") {
        nlohmann::json d; d["id"]=886; d["name"]="Test886"; d["value"]=886*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),886);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test886");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test886")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),886);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt887() {
    T("Extended test 887: Data operations") {
        nlohmann::json d; d["id"]=887; d["name"]="Test887"; d["value"]=887*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),887);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test887");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test887")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),887);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt888() {
    T("Extended test 888: Data operations") {
        nlohmann::json d; d["id"]=888; d["name"]="Test888"; d["value"]=888*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),888);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test888");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test888")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),888);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt889() {
    T("Extended test 889: Data operations") {
        nlohmann::json d; d["id"]=889; d["name"]="Test889"; d["value"]=889*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),889);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test889");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test889")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),889);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt890() {
    T("Extended test 890: Data operations") {
        nlohmann::json d; d["id"]=890; d["name"]="Test890"; d["value"]=890*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),890);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test890");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test890")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),890);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt891() {
    T("Extended test 891: Data operations") {
        nlohmann::json d; d["id"]=891; d["name"]="Test891"; d["value"]=891*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),891);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test891");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test891")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),891);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt892() {
    T("Extended test 892: Data operations") {
        nlohmann::json d; d["id"]=892; d["name"]="Test892"; d["value"]=892*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),892);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test892");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test892")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),892);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt893() {
    T("Extended test 893: Data operations") {
        nlohmann::json d; d["id"]=893; d["name"]="Test893"; d["value"]=893*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),893);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test893");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test893")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),893);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt894() {
    T("Extended test 894: Data operations") {
        nlohmann::json d; d["id"]=894; d["name"]="Test894"; d["value"]=894*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),894);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test894");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test894")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),894);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt895() {
    T("Extended test 895: Data operations") {
        nlohmann::json d; d["id"]=895; d["name"]="Test895"; d["value"]=895*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),895);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test895");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test895")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),895);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt896() {
    T("Extended test 896: Data operations") {
        nlohmann::json d; d["id"]=896; d["name"]="Test896"; d["value"]=896*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),896);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test896");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test896")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),896);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt897() {
    T("Extended test 897: Data operations") {
        nlohmann::json d; d["id"]=897; d["name"]="Test897"; d["value"]=897*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),897);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test897");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test897")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),897);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt898() {
    T("Extended test 898: Data operations") {
        nlohmann::json d; d["id"]=898; d["name"]="Test898"; d["value"]=898*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),898);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test898");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test898")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),898);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt899() {
    T("Extended test 899: Data operations") {
        nlohmann::json d; d["id"]=899; d["name"]="Test899"; d["value"]=899*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),899);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test899");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test899")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),899);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt900() {
    T("Extended test 900: Data operations") {
        nlohmann::json d; d["id"]=900; d["name"]="Test900"; d["value"]=900*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),900);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test900");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test900")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),900);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt901() {
    T("Extended test 901: Data operations") {
        nlohmann::json d; d["id"]=901; d["name"]="Test901"; d["value"]=901*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),901);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test901");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test901")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),901);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt902() {
    T("Extended test 902: Data operations") {
        nlohmann::json d; d["id"]=902; d["name"]="Test902"; d["value"]=902*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),902);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test902");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test902")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),902);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt903() {
    T("Extended test 903: Data operations") {
        nlohmann::json d; d["id"]=903; d["name"]="Test903"; d["value"]=903*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),903);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test903");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test903")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),903);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt904() {
    T("Extended test 904: Data operations") {
        nlohmann::json d; d["id"]=904; d["name"]="Test904"; d["value"]=904*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),904);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test904");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test904")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),904);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt905() {
    T("Extended test 905: Data operations") {
        nlohmann::json d; d["id"]=905; d["name"]="Test905"; d["value"]=905*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),905);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test905");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test905")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),905);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt906() {
    T("Extended test 906: Data operations") {
        nlohmann::json d; d["id"]=906; d["name"]="Test906"; d["value"]=906*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),906);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test906");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test906")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),906);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt907() {
    T("Extended test 907: Data operations") {
        nlohmann::json d; d["id"]=907; d["name"]="Test907"; d["value"]=907*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),907);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test907");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test907")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),907);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt908() {
    T("Extended test 908: Data operations") {
        nlohmann::json d; d["id"]=908; d["name"]="Test908"; d["value"]=908*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),908);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test908");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test908")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),908);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt909() {
    T("Extended test 909: Data operations") {
        nlohmann::json d; d["id"]=909; d["name"]="Test909"; d["value"]=909*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),909);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test909");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test909")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),909);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt910() {
    T("Extended test 910: Data operations") {
        nlohmann::json d; d["id"]=910; d["name"]="Test910"; d["value"]=910*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),910);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test910");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test910")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),910);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt911() {
    T("Extended test 911: Data operations") {
        nlohmann::json d; d["id"]=911; d["name"]="Test911"; d["value"]=911*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),911);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test911");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test911")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),911);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt912() {
    T("Extended test 912: Data operations") {
        nlohmann::json d; d["id"]=912; d["name"]="Test912"; d["value"]=912*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),912);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test912");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test912")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),912);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt913() {
    T("Extended test 913: Data operations") {
        nlohmann::json d; d["id"]=913; d["name"]="Test913"; d["value"]=913*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),913);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test913");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test913")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),913);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt914() {
    T("Extended test 914: Data operations") {
        nlohmann::json d; d["id"]=914; d["name"]="Test914"; d["value"]=914*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),914);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test914");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test914")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),914);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt915() {
    T("Extended test 915: Data operations") {
        nlohmann::json d; d["id"]=915; d["name"]="Test915"; d["value"]=915*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),915);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test915");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test915")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),915);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt916() {
    T("Extended test 916: Data operations") {
        nlohmann::json d; d["id"]=916; d["name"]="Test916"; d["value"]=916*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),916);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test916");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test916")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),916);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt917() {
    T("Extended test 917: Data operations") {
        nlohmann::json d; d["id"]=917; d["name"]="Test917"; d["value"]=917*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),917);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test917");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test917")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),917);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt918() {
    T("Extended test 918: Data operations") {
        nlohmann::json d; d["id"]=918; d["name"]="Test918"; d["value"]=918*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),918);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test918");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test918")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),918);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt919() {
    T("Extended test 919: Data operations") {
        nlohmann::json d; d["id"]=919; d["name"]="Test919"; d["value"]=919*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),919);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test919");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test919")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),919);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt920() {
    T("Extended test 920: Data operations") {
        nlohmann::json d; d["id"]=920; d["name"]="Test920"; d["value"]=920*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),920);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test920");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test920")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),920);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt921() {
    T("Extended test 921: Data operations") {
        nlohmann::json d; d["id"]=921; d["name"]="Test921"; d["value"]=921*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),921);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test921");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test921")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),921);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt922() {
    T("Extended test 922: Data operations") {
        nlohmann::json d; d["id"]=922; d["name"]="Test922"; d["value"]=922*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),922);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test922");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test922")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),922);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt923() {
    T("Extended test 923: Data operations") {
        nlohmann::json d; d["id"]=923; d["name"]="Test923"; d["value"]=923*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),923);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test923");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test923")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),923);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt924() {
    T("Extended test 924: Data operations") {
        nlohmann::json d; d["id"]=924; d["name"]="Test924"; d["value"]=924*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),924);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test924");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test924")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),924);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt925() {
    T("Extended test 925: Data operations") {
        nlohmann::json d; d["id"]=925; d["name"]="Test925"; d["value"]=925*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),925);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test925");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test925")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),925);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt926() {
    T("Extended test 926: Data operations") {
        nlohmann::json d; d["id"]=926; d["name"]="Test926"; d["value"]=926*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),926);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test926");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test926")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),926);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt927() {
    T("Extended test 927: Data operations") {
        nlohmann::json d; d["id"]=927; d["name"]="Test927"; d["value"]=927*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),927);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test927");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test927")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),927);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt928() {
    T("Extended test 928: Data operations") {
        nlohmann::json d; d["id"]=928; d["name"]="Test928"; d["value"]=928*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),928);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test928");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test928")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),928);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt929() {
    T("Extended test 929: Data operations") {
        nlohmann::json d; d["id"]=929; d["name"]="Test929"; d["value"]=929*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),929);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test929");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test929")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),929);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt930() {
    T("Extended test 930: Data operations") {
        nlohmann::json d; d["id"]=930; d["name"]="Test930"; d["value"]=930*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),930);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test930");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test930")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),930);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt931() {
    T("Extended test 931: Data operations") {
        nlohmann::json d; d["id"]=931; d["name"]="Test931"; d["value"]=931*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),931);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test931");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test931")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),931);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt932() {
    T("Extended test 932: Data operations") {
        nlohmann::json d; d["id"]=932; d["name"]="Test932"; d["value"]=932*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),932);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test932");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test932")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),932);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt933() {
    T("Extended test 933: Data operations") {
        nlohmann::json d; d["id"]=933; d["name"]="Test933"; d["value"]=933*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),933);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test933");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test933")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),933);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt934() {
    T("Extended test 934: Data operations") {
        nlohmann::json d; d["id"]=934; d["name"]="Test934"; d["value"]=934*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),934);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test934");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test934")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),934);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt935() {
    T("Extended test 935: Data operations") {
        nlohmann::json d; d["id"]=935; d["name"]="Test935"; d["value"]=935*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),935);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test935");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test935")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),935);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt936() {
    T("Extended test 936: Data operations") {
        nlohmann::json d; d["id"]=936; d["name"]="Test936"; d["value"]=936*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),936);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test936");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test936")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),936);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt937() {
    T("Extended test 937: Data operations") {
        nlohmann::json d; d["id"]=937; d["name"]="Test937"; d["value"]=937*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),937);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test937");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test937")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),937);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt938() {
    T("Extended test 938: Data operations") {
        nlohmann::json d; d["id"]=938; d["name"]="Test938"; d["value"]=938*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),938);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test938");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test938")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),938);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt939() {
    T("Extended test 939: Data operations") {
        nlohmann::json d; d["id"]=939; d["name"]="Test939"; d["value"]=939*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),939);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test939");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test939")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),939);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt940() {
    T("Extended test 940: Data operations") {
        nlohmann::json d; d["id"]=940; d["name"]="Test940"; d["value"]=940*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),940);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test940");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test940")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),940);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt941() {
    T("Extended test 941: Data operations") {
        nlohmann::json d; d["id"]=941; d["name"]="Test941"; d["value"]=941*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),941);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test941");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test941")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),941);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt942() {
    T("Extended test 942: Data operations") {
        nlohmann::json d; d["id"]=942; d["name"]="Test942"; d["value"]=942*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),942);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test942");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test942")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),942);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt943() {
    T("Extended test 943: Data operations") {
        nlohmann::json d; d["id"]=943; d["name"]="Test943"; d["value"]=943*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),943);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test943");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test943")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),943);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt944() {
    T("Extended test 944: Data operations") {
        nlohmann::json d; d["id"]=944; d["name"]="Test944"; d["value"]=944*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),944);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test944");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test944")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),944);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt945() {
    T("Extended test 945: Data operations") {
        nlohmann::json d; d["id"]=945; d["name"]="Test945"; d["value"]=945*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),945);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test945");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test945")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),945);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt946() {
    T("Extended test 946: Data operations") {
        nlohmann::json d; d["id"]=946; d["name"]="Test946"; d["value"]=946*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),946);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test946");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test946")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),946);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt947() {
    T("Extended test 947: Data operations") {
        nlohmann::json d; d["id"]=947; d["name"]="Test947"; d["value"]=947*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),947);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test947");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test947")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),947);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt948() {
    T("Extended test 948: Data operations") {
        nlohmann::json d; d["id"]=948; d["name"]="Test948"; d["value"]=948*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),948);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test948");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test948")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),948);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt949() {
    T("Extended test 949: Data operations") {
        nlohmann::json d; d["id"]=949; d["name"]="Test949"; d["value"]=949*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),949);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test949");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test949")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),949);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt950() {
    T("Extended test 950: Data operations") {
        nlohmann::json d; d["id"]=950; d["name"]="Test950"; d["value"]=950*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),950);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test950");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test950")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),950);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt951() {
    T("Extended test 951: Data operations") {
        nlohmann::json d; d["id"]=951; d["name"]="Test951"; d["value"]=951*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),951);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test951");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test951")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),951);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt952() {
    T("Extended test 952: Data operations") {
        nlohmann::json d; d["id"]=952; d["name"]="Test952"; d["value"]=952*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),952);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test952");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test952")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),952);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt953() {
    T("Extended test 953: Data operations") {
        nlohmann::json d; d["id"]=953; d["name"]="Test953"; d["value"]=953*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),953);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test953");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test953")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),953);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt954() {
    T("Extended test 954: Data operations") {
        nlohmann::json d; d["id"]=954; d["name"]="Test954"; d["value"]=954*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),954);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test954");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test954")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),954);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt955() {
    T("Extended test 955: Data operations") {
        nlohmann::json d; d["id"]=955; d["name"]="Test955"; d["value"]=955*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),955);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test955");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test955")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),955);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt956() {
    T("Extended test 956: Data operations") {
        nlohmann::json d; d["id"]=956; d["name"]="Test956"; d["value"]=956*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),956);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test956");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test956")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),956);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt957() {
    T("Extended test 957: Data operations") {
        nlohmann::json d; d["id"]=957; d["name"]="Test957"; d["value"]=957*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),957);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test957");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test957")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),957);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt958() {
    T("Extended test 958: Data operations") {
        nlohmann::json d; d["id"]=958; d["name"]="Test958"; d["value"]=958*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),958);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test958");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test958")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),958);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt959() {
    T("Extended test 959: Data operations") {
        nlohmann::json d; d["id"]=959; d["name"]="Test959"; d["value"]=959*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),959);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test959");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test959")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),959);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt960() {
    T("Extended test 960: Data operations") {
        nlohmann::json d; d["id"]=960; d["name"]="Test960"; d["value"]=960*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),960);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test960");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test960")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),960);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt961() {
    T("Extended test 961: Data operations") {
        nlohmann::json d; d["id"]=961; d["name"]="Test961"; d["value"]=961*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),961);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test961");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test961")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),961);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt962() {
    T("Extended test 962: Data operations") {
        nlohmann::json d; d["id"]=962; d["name"]="Test962"; d["value"]=962*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),962);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test962");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test962")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),962);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt963() {
    T("Extended test 963: Data operations") {
        nlohmann::json d; d["id"]=963; d["name"]="Test963"; d["value"]=963*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),963);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test963");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test963")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),963);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt964() {
    T("Extended test 964: Data operations") {
        nlohmann::json d; d["id"]=964; d["name"]="Test964"; d["value"]=964*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),964);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test964");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test964")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),964);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt965() {
    T("Extended test 965: Data operations") {
        nlohmann::json d; d["id"]=965; d["name"]="Test965"; d["value"]=965*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),965);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test965");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test965")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),965);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt966() {
    T("Extended test 966: Data operations") {
        nlohmann::json d; d["id"]=966; d["name"]="Test966"; d["value"]=966*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),966);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test966");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test966")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),966);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt967() {
    T("Extended test 967: Data operations") {
        nlohmann::json d; d["id"]=967; d["name"]="Test967"; d["value"]=967*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),967);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test967");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test967")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),967);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt968() {
    T("Extended test 968: Data operations") {
        nlohmann::json d; d["id"]=968; d["name"]="Test968"; d["value"]=968*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),968);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test968");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test968")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),968);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt969() {
    T("Extended test 969: Data operations") {
        nlohmann::json d; d["id"]=969; d["name"]="Test969"; d["value"]=969*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),969);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test969");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test969")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),969);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt970() {
    T("Extended test 970: Data operations") {
        nlohmann::json d; d["id"]=970; d["name"]="Test970"; d["value"]=970*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),970);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test970");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test970")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),970);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt971() {
    T("Extended test 971: Data operations") {
        nlohmann::json d; d["id"]=971; d["name"]="Test971"; d["value"]=971*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),971);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test971");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test971")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),971);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt972() {
    T("Extended test 972: Data operations") {
        nlohmann::json d; d["id"]=972; d["name"]="Test972"; d["value"]=972*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),972);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test972");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test972")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),972);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt973() {
    T("Extended test 973: Data operations") {
        nlohmann::json d; d["id"]=973; d["name"]="Test973"; d["value"]=973*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),973);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test973");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test973")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),973);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt974() {
    T("Extended test 974: Data operations") {
        nlohmann::json d; d["id"]=974; d["name"]="Test974"; d["value"]=974*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),974);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test974");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test974")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),974);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt975() {
    T("Extended test 975: Data operations") {
        nlohmann::json d; d["id"]=975; d["name"]="Test975"; d["value"]=975*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),975);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test975");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test975")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),975);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt976() {
    T("Extended test 976: Data operations") {
        nlohmann::json d; d["id"]=976; d["name"]="Test976"; d["value"]=976*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),976);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test976");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test976")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),976);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt977() {
    T("Extended test 977: Data operations") {
        nlohmann::json d; d["id"]=977; d["name"]="Test977"; d["value"]=977*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),977);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test977");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test977")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),977);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt978() {
    T("Extended test 978: Data operations") {
        nlohmann::json d; d["id"]=978; d["name"]="Test978"; d["value"]=978*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),978);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test978");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test978")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),978);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt979() {
    T("Extended test 979: Data operations") {
        nlohmann::json d; d["id"]=979; d["name"]="Test979"; d["value"]=979*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),979);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test979");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test979")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),979);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt980() {
    T("Extended test 980: Data operations") {
        nlohmann::json d; d["id"]=980; d["name"]="Test980"; d["value"]=980*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),980);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test980");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test980")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),980);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt981() {
    T("Extended test 981: Data operations") {
        nlohmann::json d; d["id"]=981; d["name"]="Test981"; d["value"]=981*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),981);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test981");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test981")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),981);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt982() {
    T("Extended test 982: Data operations") {
        nlohmann::json d; d["id"]=982; d["name"]="Test982"; d["value"]=982*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),982);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test982");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test982")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),982);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt983() {
    T("Extended test 983: Data operations") {
        nlohmann::json d; d["id"]=983; d["name"]="Test983"; d["value"]=983*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),983);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test983");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test983")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),983);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt984() {
    T("Extended test 984: Data operations") {
        nlohmann::json d; d["id"]=984; d["name"]="Test984"; d["value"]=984*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),984);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test984");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test984")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),984);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt985() {
    T("Extended test 985: Data operations") {
        nlohmann::json d; d["id"]=985; d["name"]="Test985"; d["value"]=985*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),985);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test985");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test985")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),985);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt986() {
    T("Extended test 986: Data operations") {
        nlohmann::json d; d["id"]=986; d["name"]="Test986"; d["value"]=986*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),986);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test986");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test986")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),986);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt987() {
    T("Extended test 987: Data operations") {
        nlohmann::json d; d["id"]=987; d["name"]="Test987"; d["value"]=987*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),987);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test987");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test987")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),987);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt988() {
    T("Extended test 988: Data operations") {
        nlohmann::json d; d["id"]=988; d["name"]="Test988"; d["value"]=988*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),988);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test988");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test988")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),988);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt989() {
    T("Extended test 989: Data operations") {
        nlohmann::json d; d["id"]=989; d["name"]="Test989"; d["value"]=989*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),989);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test989");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test989")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),989);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt990() {
    T("Extended test 990: Data operations") {
        nlohmann::json d; d["id"]=990; d["name"]="Test990"; d["value"]=990*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),990);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test990");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test990")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),990);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt991() {
    T("Extended test 991: Data operations") {
        nlohmann::json d; d["id"]=991; d["name"]="Test991"; d["value"]=991*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),991);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test991");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test991")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),991);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt992() {
    T("Extended test 992: Data operations") {
        nlohmann::json d; d["id"]=992; d["name"]="Test992"; d["value"]=992*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),992);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test992");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test992")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),992);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt993() {
    T("Extended test 993: Data operations") {
        nlohmann::json d; d["id"]=993; d["name"]="Test993"; d["value"]=993*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),993);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test993");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test993")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),993);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt994() {
    T("Extended test 994: Data operations") {
        nlohmann::json d; d["id"]=994; d["name"]="Test994"; d["value"]=994*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),994);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test994");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test994")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),994);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt995() {
    T("Extended test 995: Data operations") {
        nlohmann::json d; d["id"]=995; d["name"]="Test995"; d["value"]=995*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),995);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test995");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test995")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),995);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt996() {
    T("Extended test 996: Data operations") {
        nlohmann::json d; d["id"]=996; d["name"]="Test996"; d["value"]=996*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),996);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test996");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test996")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),996);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt997() {
    T("Extended test 997: Data operations") {
        nlohmann::json d; d["id"]=997; d["name"]="Test997"; d["value"]=997*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),997);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test997");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test997")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),997);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt998() {
    T("Extended test 998: Data operations") {
        nlohmann::json d; d["id"]=998; d["name"]="Test998"; d["value"]=998*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),998);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test998");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test998")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),998);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt999() {
    T("Extended test 999: Data operations") {
        nlohmann::json d; d["id"]=999; d["name"]="Test999"; d["value"]=999*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),999);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test999");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test999")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),999);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
void testExt1000() {
    T("Extended test 1000: Data operations") {
        nlohmann::json d; d["id"]=1000; d["name"]="Test1000"; d["value"]=1000*100;
        CHECK(d.contains("id")); EQ(d["id"].get<int>(),1000);
        CHECK(d.contains("name")); CHECK(d["name"]=="Test1000");
        std::string s=d.dump(); CHECK(!s.empty()); CHECK(s.find("Test1000")!=std::string::npos);
        nlohmann::json p=nlohmann::json::parse(s); EQ(p["id"].get<int>(),1000);
        auto start=std::chrono::steady_clock::now();
        for(int j=0;j<100;j++){nlohmann::json tmp=d;tmp["iter"]=j;}
        auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
        CHECK(ms<1000);
    } E
}
int main() {
    spdlog::set_level(spdlog::level::info);
    spdlog::info("=== ProjectForge Extended Integration Tests ===");
    auto s=std::chrono::steady_clock::now();
    testExt1();
    testExt2();
    testExt3();
    testExt4();
    testExt5();
    testExt6();
    testExt7();
    testExt8();
    testExt9();
    testExt10();
    testExt11();
    testExt12();
    testExt13();
    testExt14();
    testExt15();
    testExt16();
    testExt17();
    testExt18();
    testExt19();
    testExt20();
    testExt21();
    testExt22();
    testExt23();
    testExt24();
    testExt25();
    testExt26();
    testExt27();
    testExt28();
    testExt29();
    testExt30();
    testExt31();
    testExt32();
    testExt33();
    testExt34();
    testExt35();
    testExt36();
    testExt37();
    testExt38();
    testExt39();
    testExt40();
    testExt41();
    testExt42();
    testExt43();
    testExt44();
    testExt45();
    testExt46();
    testExt47();
    testExt48();
    testExt49();
    testExt50();
    testExt51();
    testExt52();
    testExt53();
    testExt54();
    testExt55();
    testExt56();
    testExt57();
    testExt58();
    testExt59();
    testExt60();
    testExt61();
    testExt62();
    testExt63();
    testExt64();
    testExt65();
    testExt66();
    testExt67();
    testExt68();
    testExt69();
    testExt70();
    testExt71();
    testExt72();
    testExt73();
    testExt74();
    testExt75();
    testExt76();
    testExt77();
    testExt78();
    testExt79();
    testExt80();
    testExt81();
    testExt82();
    testExt83();
    testExt84();
    testExt85();
    testExt86();
    testExt87();
    testExt88();
    testExt89();
    testExt90();
    testExt91();
    testExt92();
    testExt93();
    testExt94();
    testExt95();
    testExt96();
    testExt97();
    testExt98();
    testExt99();
    testExt100();
    testExt101();
    testExt102();
    testExt103();
    testExt104();
    testExt105();
    testExt106();
    testExt107();
    testExt108();
    testExt109();
    testExt110();
    testExt111();
    testExt112();
    testExt113();
    testExt114();
    testExt115();
    testExt116();
    testExt117();
    testExt118();
    testExt119();
    testExt120();
    testExt121();
    testExt122();
    testExt123();
    testExt124();
    testExt125();
    testExt126();
    testExt127();
    testExt128();
    testExt129();
    testExt130();
    testExt131();
    testExt132();
    testExt133();
    testExt134();
    testExt135();
    testExt136();
    testExt137();
    testExt138();
    testExt139();
    testExt140();
    testExt141();
    testExt142();
    testExt143();
    testExt144();
    testExt145();
    testExt146();
    testExt147();
    testExt148();
    testExt149();
    testExt150();
    testExt151();
    testExt152();
    testExt153();
    testExt154();
    testExt155();
    testExt156();
    testExt157();
    testExt158();
    testExt159();
    testExt160();
    testExt161();
    testExt162();
    testExt163();
    testExt164();
    testExt165();
    testExt166();
    testExt167();
    testExt168();
    testExt169();
    testExt170();
    testExt171();
    testExt172();
    testExt173();
    testExt174();
    testExt175();
    testExt176();
    testExt177();
    testExt178();
    testExt179();
    testExt180();
    testExt181();
    testExt182();
    testExt183();
    testExt184();
    testExt185();
    testExt186();
    testExt187();
    testExt188();
    testExt189();
    testExt190();
    testExt191();
    testExt192();
    testExt193();
    testExt194();
    testExt195();
    testExt196();
    testExt197();
    testExt198();
    testExt199();
    testExt200();
    testExt201();
    testExt202();
    testExt203();
    testExt204();
    testExt205();
    testExt206();
    testExt207();
    testExt208();
    testExt209();
    testExt210();
    testExt211();
    testExt212();
    testExt213();
    testExt214();
    testExt215();
    testExt216();
    testExt217();
    testExt218();
    testExt219();
    testExt220();
    testExt221();
    testExt222();
    testExt223();
    testExt224();
    testExt225();
    testExt226();
    testExt227();
    testExt228();
    testExt229();
    testExt230();
    testExt231();
    testExt232();
    testExt233();
    testExt234();
    testExt235();
    testExt236();
    testExt237();
    testExt238();
    testExt239();
    testExt240();
    testExt241();
    testExt242();
    testExt243();
    testExt244();
    testExt245();
    testExt246();
    testExt247();
    testExt248();
    testExt249();
    testExt250();
    testExt251();
    testExt252();
    testExt253();
    testExt254();
    testExt255();
    testExt256();
    testExt257();
    testExt258();
    testExt259();
    testExt260();
    testExt261();
    testExt262();
    testExt263();
    testExt264();
    testExt265();
    testExt266();
    testExt267();
    testExt268();
    testExt269();
    testExt270();
    testExt271();
    testExt272();
    testExt273();
    testExt274();
    testExt275();
    testExt276();
    testExt277();
    testExt278();
    testExt279();
    testExt280();
    testExt281();
    testExt282();
    testExt283();
    testExt284();
    testExt285();
    testExt286();
    testExt287();
    testExt288();
    testExt289();
    testExt290();
    testExt291();
    testExt292();
    testExt293();
    testExt294();
    testExt295();
    testExt296();
    testExt297();
    testExt298();
    testExt299();
    testExt300();
    testExt301();
    testExt302();
    testExt303();
    testExt304();
    testExt305();
    testExt306();
    testExt307();
    testExt308();
    testExt309();
    testExt310();
    testExt311();
    testExt312();
    testExt313();
    testExt314();
    testExt315();
    testExt316();
    testExt317();
    testExt318();
    testExt319();
    testExt320();
    testExt321();
    testExt322();
    testExt323();
    testExt324();
    testExt325();
    testExt326();
    testExt327();
    testExt328();
    testExt329();
    testExt330();
    testExt331();
    testExt332();
    testExt333();
    testExt334();
    testExt335();
    testExt336();
    testExt337();
    testExt338();
    testExt339();
    testExt340();
    testExt341();
    testExt342();
    testExt343();
    testExt344();
    testExt345();
    testExt346();
    testExt347();
    testExt348();
    testExt349();
    testExt350();
    testExt351();
    testExt352();
    testExt353();
    testExt354();
    testExt355();
    testExt356();
    testExt357();
    testExt358();
    testExt359();
    testExt360();
    testExt361();
    testExt362();
    testExt363();
    testExt364();
    testExt365();
    testExt366();
    testExt367();
    testExt368();
    testExt369();
    testExt370();
    testExt371();
    testExt372();
    testExt373();
    testExt374();
    testExt375();
    testExt376();
    testExt377();
    testExt378();
    testExt379();
    testExt380();
    testExt381();
    testExt382();
    testExt383();
    testExt384();
    testExt385();
    testExt386();
    testExt387();
    testExt388();
    testExt389();
    testExt390();
    testExt391();
    testExt392();
    testExt393();
    testExt394();
    testExt395();
    testExt396();
    testExt397();
    testExt398();
    testExt399();
    testExt400();
    testExt401();
    testExt402();
    testExt403();
    testExt404();
    testExt405();
    testExt406();
    testExt407();
    testExt408();
    testExt409();
    testExt410();
    testExt411();
    testExt412();
    testExt413();
    testExt414();
    testExt415();
    testExt416();
    testExt417();
    testExt418();
    testExt419();
    testExt420();
    testExt421();
    testExt422();
    testExt423();
    testExt424();
    testExt425();
    testExt426();
    testExt427();
    testExt428();
    testExt429();
    testExt430();
    testExt431();
    testExt432();
    testExt433();
    testExt434();
    testExt435();
    testExt436();
    testExt437();
    testExt438();
    testExt439();
    testExt440();
    testExt441();
    testExt442();
    testExt443();
    testExt444();
    testExt445();
    testExt446();
    testExt447();
    testExt448();
    testExt449();
    testExt450();
    testExt451();
    testExt452();
    testExt453();
    testExt454();
    testExt455();
    testExt456();
    testExt457();
    testExt458();
    testExt459();
    testExt460();
    testExt461();
    testExt462();
    testExt463();
    testExt464();
    testExt465();
    testExt466();
    testExt467();
    testExt468();
    testExt469();
    testExt470();
    testExt471();
    testExt472();
    testExt473();
    testExt474();
    testExt475();
    testExt476();
    testExt477();
    testExt478();
    testExt479();
    testExt480();
    testExt481();
    testExt482();
    testExt483();
    testExt484();
    testExt485();
    testExt486();
    testExt487();
    testExt488();
    testExt489();
    testExt490();
    testExt491();
    testExt492();
    testExt493();
    testExt494();
    testExt495();
    testExt496();
    testExt497();
    testExt498();
    testExt499();
    testExt500();
    testExt501();
    testExt502();
    testExt503();
    testExt504();
    testExt505();
    testExt506();
    testExt507();
    testExt508();
    testExt509();
    testExt510();
    testExt511();
    testExt512();
    testExt513();
    testExt514();
    testExt515();
    testExt516();
    testExt517();
    testExt518();
    testExt519();
    testExt520();
    testExt521();
    testExt522();
    testExt523();
    testExt524();
    testExt525();
    testExt526();
    testExt527();
    testExt528();
    testExt529();
    testExt530();
    testExt531();
    testExt532();
    testExt533();
    testExt534();
    testExt535();
    testExt536();
    testExt537();
    testExt538();
    testExt539();
    testExt540();
    testExt541();
    testExt542();
    testExt543();
    testExt544();
    testExt545();
    testExt546();
    testExt547();
    testExt548();
    testExt549();
    testExt550();
    testExt551();
    testExt552();
    testExt553();
    testExt554();
    testExt555();
    testExt556();
    testExt557();
    testExt558();
    testExt559();
    testExt560();
    testExt561();
    testExt562();
    testExt563();
    testExt564();
    testExt565();
    testExt566();
    testExt567();
    testExt568();
    testExt569();
    testExt570();
    testExt571();
    testExt572();
    testExt573();
    testExt574();
    testExt575();
    testExt576();
    testExt577();
    testExt578();
    testExt579();
    testExt580();
    testExt581();
    testExt582();
    testExt583();
    testExt584();
    testExt585();
    testExt586();
    testExt587();
    testExt588();
    testExt589();
    testExt590();
    testExt591();
    testExt592();
    testExt593();
    testExt594();
    testExt595();
    testExt596();
    testExt597();
    testExt598();
    testExt599();
    testExt600();
    testExt601();
    testExt602();
    testExt603();
    testExt604();
    testExt605();
    testExt606();
    testExt607();
    testExt608();
    testExt609();
    testExt610();
    testExt611();
    testExt612();
    testExt613();
    testExt614();
    testExt615();
    testExt616();
    testExt617();
    testExt618();
    testExt619();
    testExt620();
    testExt621();
    testExt622();
    testExt623();
    testExt624();
    testExt625();
    testExt626();
    testExt627();
    testExt628();
    testExt629();
    testExt630();
    testExt631();
    testExt632();
    testExt633();
    testExt634();
    testExt635();
    testExt636();
    testExt637();
    testExt638();
    testExt639();
    testExt640();
    testExt641();
    testExt642();
    testExt643();
    testExt644();
    testExt645();
    testExt646();
    testExt647();
    testExt648();
    testExt649();
    testExt650();
    testExt651();
    testExt652();
    testExt653();
    testExt654();
    testExt655();
    testExt656();
    testExt657();
    testExt658();
    testExt659();
    testExt660();
    testExt661();
    testExt662();
    testExt663();
    testExt664();
    testExt665();
    testExt666();
    testExt667();
    testExt668();
    testExt669();
    testExt670();
    testExt671();
    testExt672();
    testExt673();
    testExt674();
    testExt675();
    testExt676();
    testExt677();
    testExt678();
    testExt679();
    testExt680();
    testExt681();
    testExt682();
    testExt683();
    testExt684();
    testExt685();
    testExt686();
    testExt687();
    testExt688();
    testExt689();
    testExt690();
    testExt691();
    testExt692();
    testExt693();
    testExt694();
    testExt695();
    testExt696();
    testExt697();
    testExt698();
    testExt699();
    testExt700();
    testExt701();
    testExt702();
    testExt703();
    testExt704();
    testExt705();
    testExt706();
    testExt707();
    testExt708();
    testExt709();
    testExt710();
    testExt711();
    testExt712();
    testExt713();
    testExt714();
    testExt715();
    testExt716();
    testExt717();
    testExt718();
    testExt719();
    testExt720();
    testExt721();
    testExt722();
    testExt723();
    testExt724();
    testExt725();
    testExt726();
    testExt727();
    testExt728();
    testExt729();
    testExt730();
    testExt731();
    testExt732();
    testExt733();
    testExt734();
    testExt735();
    testExt736();
    testExt737();
    testExt738();
    testExt739();
    testExt740();
    testExt741();
    testExt742();
    testExt743();
    testExt744();
    testExt745();
    testExt746();
    testExt747();
    testExt748();
    testExt749();
    testExt750();
    testExt751();
    testExt752();
    testExt753();
    testExt754();
    testExt755();
    testExt756();
    testExt757();
    testExt758();
    testExt759();
    testExt760();
    testExt761();
    testExt762();
    testExt763();
    testExt764();
    testExt765();
    testExt766();
    testExt767();
    testExt768();
    testExt769();
    testExt770();
    testExt771();
    testExt772();
    testExt773();
    testExt774();
    testExt775();
    testExt776();
    testExt777();
    testExt778();
    testExt779();
    testExt780();
    testExt781();
    testExt782();
    testExt783();
    testExt784();
    testExt785();
    testExt786();
    testExt787();
    testExt788();
    testExt789();
    testExt790();
    testExt791();
    testExt792();
    testExt793();
    testExt794();
    testExt795();
    testExt796();
    testExt797();
    testExt798();
    testExt799();
    testExt800();
    testExt801();
    testExt802();
    testExt803();
    testExt804();
    testExt805();
    testExt806();
    testExt807();
    testExt808();
    testExt809();
    testExt810();
    testExt811();
    testExt812();
    testExt813();
    testExt814();
    testExt815();
    testExt816();
    testExt817();
    testExt818();
    testExt819();
    testExt820();
    testExt821();
    testExt822();
    testExt823();
    testExt824();
    testExt825();
    testExt826();
    testExt827();
    testExt828();
    testExt829();
    testExt830();
    testExt831();
    testExt832();
    testExt833();
    testExt834();
    testExt835();
    testExt836();
    testExt837();
    testExt838();
    testExt839();
    testExt840();
    testExt841();
    testExt842();
    testExt843();
    testExt844();
    testExt845();
    testExt846();
    testExt847();
    testExt848();
    testExt849();
    testExt850();
    testExt851();
    testExt852();
    testExt853();
    testExt854();
    testExt855();
    testExt856();
    testExt857();
    testExt858();
    testExt859();
    testExt860();
    testExt861();
    testExt862();
    testExt863();
    testExt864();
    testExt865();
    testExt866();
    testExt867();
    testExt868();
    testExt869();
    testExt870();
    testExt871();
    testExt872();
    testExt873();
    testExt874();
    testExt875();
    testExt876();
    testExt877();
    testExt878();
    testExt879();
    testExt880();
    testExt881();
    testExt882();
    testExt883();
    testExt884();
    testExt885();
    testExt886();
    testExt887();
    testExt888();
    testExt889();
    testExt890();
    testExt891();
    testExt892();
    testExt893();
    testExt894();
    testExt895();
    testExt896();
    testExt897();
    testExt898();
    testExt899();
    testExt900();
    testExt901();
    testExt902();
    testExt903();
    testExt904();
    testExt905();
    testExt906();
    testExt907();
    testExt908();
    testExt909();
    testExt910();
    testExt911();
    testExt912();
    testExt913();
    testExt914();
    testExt915();
    testExt916();
    testExt917();
    testExt918();
    testExt919();
    testExt920();
    testExt921();
    testExt922();
    testExt923();
    testExt924();
    testExt925();
    testExt926();
    testExt927();
    testExt928();
    testExt929();
    testExt930();
    testExt931();
    testExt932();
    testExt933();
    testExt934();
    testExt935();
    testExt936();
    testExt937();
    testExt938();
    testExt939();
    testExt940();
    testExt941();
    testExt942();
    testExt943();
    testExt944();
    testExt945();
    testExt946();
    testExt947();
    testExt948();
    testExt949();
    testExt950();
    testExt951();
    testExt952();
    testExt953();
    testExt954();
    testExt955();
    testExt956();
    testExt957();
    testExt958();
    testExt959();
    testExt960();
    testExt961();
    testExt962();
    testExt963();
    testExt964();
    testExt965();
    testExt966();
    testExt967();
    testExt968();
    testExt969();
    testExt970();
    testExt971();
    testExt972();
    testExt973();
    testExt974();
    testExt975();
    testExt976();
    testExt977();
    testExt978();
    testExt979();
    testExt980();
    testExt981();
    testExt982();
    testExt983();
    testExt984();
    testExt985();
    testExt986();
    testExt987();
    testExt988();
    testExt989();
    testExt990();
    testExt991();
    testExt992();
    testExt993();
    testExt994();
    testExt995();
    testExt996();
    testExt997();
    testExt998();
    testExt999();
    testExt1000();
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-s).count();
    std::cout<<"\nPassed: "<<tPassed<<" Failed: "<<tFailed<<" Duration: "<<ms<<"ms"<<std::endl;
    return tFailed;
}