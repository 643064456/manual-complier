//
// Created by xiaoyu ren on 2022/11/21.
//

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H
#include <string_view>
#include <memory>

namespace compiler {

    enum class TokenKind{
        Add,
        Sub,
        Mul,
        Div,
        Num,
        Eof,
        Null
    };

    class Token{
    public:
        TokenKind kind;
        int value;
        std::string_view content;
    };

    class Lexer {
    private:
        std::string_view sourceCode;
        std::shared_ptr<Token> currentToken;
        char currentChar{' '};
        int cursor{0};
    public:
        Lexer(const char *code){
            sourceCode = code;
        }
        void GetNextToken();
        void GetNextChar();
        std::shared_ptr<Token> GetCurrentToken();
    };
}


#endif //COMPILER_LEXER_H
