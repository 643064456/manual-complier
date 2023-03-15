//
// Created by xiaoyu ren on 2022/11/21.
//

#include "Lexer.h"

void compiler::Lexer::GetNextToken() {
    while (isspace(currentChar)){
        GetNextChar();
    }
    TokenKind kind = TokenKind::Null;
    int value = 0;
    int startPos = cursor -1;
    if (currentChar == '\0'){
        kind = TokenKind::Eof;
    }
    else if (currentChar == '+'){
        kind = TokenKind::Add;
        GetNextChar();
    }
    else if (currentChar == '-'){
        kind = TokenKind::Sub;
        GetNextChar();
    }
    else if (currentChar == '*'){
        kind = TokenKind::Mul;
        GetNextChar();
    }
    else if (currentChar == '/'){
        kind = TokenKind::Div;
        GetNextChar();
    }
    else if (std::isdigit(currentChar)){
        value = 0;
        kind = TokenKind::Num;
        do{
            value = value * 10 + currentChar - '0';
            GetNextChar();
        } while (isdigit(currentChar));
    } else {
        printf("error:invalid type\n");
    }
    currentToken = std::make_shared<Token>();
    currentToken->kind = kind;
    currentToken->value = value;
    currentToken->content = sourceCode.substr(startPos, cursor - startPos - 1);
}

void compiler::Lexer::GetNextChar() {
    if (cursor >= sourceCode.size()){
        currentChar = '\0';
        cursor++;
    } else {
        currentChar = sourceCode[cursor++];
    }
}

std::shared_ptr<compiler::Token> compiler::Lexer::GetCurrentToken() {
    return currentToken;
}
