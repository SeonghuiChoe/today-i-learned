{-
    2017-02-16
    역삼각형 출력하기 - Lambda
    ex) Input: 3
        Ouput: ***
               **
               *
-}               

import System.Environment

loop 0 _ = return ()
loop n action = do
    action n
    loop (n - 1) action

star n = do
    loop n (\ n -> putStr "*")
    putStrLn ""

triangle n = do
    loop n star

main =  do 
    arg <- getArgs; 
    triangle (read $ head arg :: Int)    
        
