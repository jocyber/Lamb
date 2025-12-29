module Main where

import Lamb.Parser (getTokens)

main :: IO ()
main = print $ getTokens "\"hello\""
