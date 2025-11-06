#include <catch2/catch_test_macros.hpp>
#include <string>

#include "smart_ptr.h"

TEST_CASE("Empty shared") {
  SharedPtr<std::string> a;
  SharedPtr<std::string> b;
  b = a;
  auto c = a;
  b = std::move(c);

  REQUIRE(a.Get() == nullptr);
  REQUIRE(b.Get() == nullptr);
}

TEST_CASE("Reset shared") {
  auto *ptr1 = new std::string{"aba"};
  auto *ptr2 = new std::string{"caba"};
  SharedPtr<std::string> a{ptr1};
  SharedPtr<std::string> b{ptr2};

  REQUIRE(a.Get() == ptr1);
  REQUIRE(&*b == ptr2);
  REQUIRE(*b == *ptr2);
  a.Reset(nullptr);
  b = a;
}

TEST_CASE("Copy/move shared") {
  SharedPtr a{new std::string{"aba"}};
  std::string *ptr;
  {
    const auto b = a;
    bool dasdas = &*a == &*b;
    REQUIRE(dasdas);
    auto c = a;
    ptr = c.Get();
  }

  REQUIRE(ptr == a.Get());
  REQUIRE(ptr == &*a);
  REQUIRE(*ptr == "aba");

  SharedPtr b{new std::string{"caba"}};
  {
    auto c = b;
    auto d = b;
    d = std::move(a);
    REQUIRE(*c == "caba");
    REQUIRE(*d == "aba");
    b.Reset(new std::string{"test"});
    REQUIRE(*c == "caba");
  }
  REQUIRE(*b == "test");

  SharedPtr<std::string> end;
  {
    SharedPtr d{new std::string{"delete"}};
    d = b;
    auto c = std::move(b);
    REQUIRE(*d == "test");
    REQUIRE(*c == "test");
    const auto &r = d;
    d = r;
    c = end;
    d.Reset(new std::string{"delete"});
    end = d;
  }

  {
    SharedPtr a{new std::string{"move"}};
    auto &r = a;
    a = std::move(r);
    REQUIRE(*r == "move");
  }

  REQUIRE(*end == "delete");
}

TEST_CASE("Empty weak") {
  WeakPtr<std::string> a;
  WeakPtr<std::string> b;
  a = b;
  auto c = a;
  b = std::move(c);

  auto shared = b.Lock();
  REQUIRE(shared.Get() == nullptr);
}

TEST_CASE("Weak expiration") {
  WeakPtr<std::string> *a;
  {
    SharedPtr b{new std::string{"aba"}};
    auto c = b;
    a = new WeakPtr{c};
    auto test = a->Lock();
    REQUIRE(*test == "aba");
    bool boda = a->IsExpired();
    REQUIRE_FALSE(boda);
  }
  bool boda = a->IsExpired();
  REQUIRE(boda);
  REQUIRE(a->IsExpired());
  delete a;
}

TEST_CASE("Shared from weak") {
  auto *x = new SharedPtr{new std::string{"aba"}};
  WeakPtr y{*x};
  delete x;
  bool das = y.IsExpired();
  REQUIRE(das);

  SharedPtr z{y};
  bool s = z.Get() == nullptr;
  REQUIRE(s);
}
