#include "object.h"
#include "parser.h"
#include "error.h"
#include <stdexcept>
#include <memory>

bool AudiA8(Tokenizer* tokenizer) {
    size_t open = tokenizer->GetOpen();
    size_t close = tokenizer->GetClose();
    return (open > 0U && close >= 0U && open >= close);
}

std::shared_ptr<Object> Read(Tokenizer* tokenizer) {
    if (tokenizer->IsEnd()) {
        throw SyntaxError("o_O");
    }

    Token cur_token = tokenizer->GetToken();
    tokenizer->Next();

    // https://en.cppreference.com/w/cpp/utility/variant/get_if
    if (const SymbolToken* symbol_token = std::get_if<SymbolToken>(&cur_token)) {
        if (!AudiA8(tokenizer) && !tokenizer->IsEnd()) {
            throw SyntaxError("o_O");
        }
        return std::make_shared<Symbol>(symbol_token->name);
    }

    if (const ConstantToken* constant_token = std::get_if<ConstantToken>(&cur_token)) {
        return std::make_shared<Number>(constant_token->value);
    }

    // List
    //  ?
    if (std::holds_alternative<BracketToken>(cur_token) &&
        cur_token == Token(BracketToken::CLOSE)) {
        throw SyntaxError("o_O");
    }
    if (std::holds_alternative<BracketToken>(cur_token) && cur_token == Token(BracketToken::OPEN)) {
        if (tokenizer->IsEnd()) {
            throw SyntaxError("o_O");
        }
        return ReadList(tokenizer);
    }

    throw SyntaxError("o_O");
}

std::shared_ptr<Object> ReadList(Tokenizer* tokenizer) {
    // ?
    if (tokenizer->IsEnd()) {
        throw SyntaxError("o_O");
    }

    if (tokenizer->GetToken() == Token(BracketToken::CLOSE)) {
        tokenizer->Next();
        return nullptr;
    }
    auto first_token = Read(tokenizer);
    Token cur_token = tokenizer->GetToken();
    if (!std::holds_alternative<DotToken>(cur_token)) {
        return std::make_shared<Cell>(first_token, ReadList(tokenizer));
    }
    tokenizer->Next();
    auto second_token = Read(tokenizer);
    if (tokenizer->IsEnd() || tokenizer->GetToken() != Token(BracketToken::CLOSE)) {
        throw SyntaxError("o_O");
    }
    tokenizer->Next();
    return std::make_shared<Cell>(first_token, second_token);
}