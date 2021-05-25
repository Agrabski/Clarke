#pragma once

#define PROPERTY(NAME, INDEX) auto const& NAME() const noexcept {return std::get<INDEX>(*this);}
#define MESSAGE_CONSTRUCTORS(X) using Message::Message;\
~X() noexcept = default;
#define VALUE_CONSTRUCTORS() using tuple::tuple;
