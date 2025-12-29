module Lamb.Parser (getTokens) where

data TokenType = 
    String
  | Number
  | Whitespace
  | Assignment
  deriving (Show)

data Token =
  Token 
  { lexeme       :: String
  , tokenType    :: TokenType
  } deriving (Show)

getTokens :: String -> [Token]
getTokens [] = []
getTokens ('=':cs) = 
  Token 
  { lexeme    = "="
  , tokenType = Assignment
  } : getTokens cs
