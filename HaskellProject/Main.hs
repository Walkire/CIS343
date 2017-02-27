import Data.Char
import Data.Time.Clock
import Data.Time.Calendar

taxRate = 0.065

digitize :: Integer -> [Integer]
digitize n = [toInteger (digitToInt x ) | x <- show n] 

cardType :: Integer -> String
cardType x 
	| (head (digitize x)) == 4 = "Visa"
	| (head (digitize x)) == 5 = "MasterCard"
	| (head (digitize x)) == 6 = "Discover"
	| otherwise = "Not Accepted"

pastDate :: Integer -> Int -> Int -> IO Bool
pastDate year month day = do
	c <- getCurrentTime
	let (y,m,d) = toGregorian $ utctDay c
	let cYear = year - y
	let cMonth = month - m
	let cDay = day - d
	if cYear > 0
		then return True
		else if cMonth > 0
			then return True
			else if cDay > 0
				then return True
	else return False 

calcTax :: Float -> Float
calcTax x = (x * taxRate)

verifyCard :: Integer -> IO(Bool)
verifyCard cardNumber = do
	putStrLn "Enter expiration year: "
	a <- getLine
	let exYear = (read a::Integer)
	putStrLn "Enter expiration month: "
	b <- getLine
	let exMonth = (read b::Int)
	putStrLn "Enter expiration day: "
	c <- getLine
	let exDay = (read c::Int)
	let validNum = cardType cardNumber
	validEx <- pastDate exYear exMonth exDay
	if validNum == "Not Accepted"
		then return False
		else if not(validEx)
			then return False
	else return True

checkOut :: Float -> IO()
checkOut num = do
	putStrLn "Enter cost: "
	cost <- getLine
	let amount = (read cost::Float)
	if amount /= 0
		then do putStrLn (show amount)
			checkOut(amount + num)
		else putStrLn (show(amount+(num+(calcTax(amount+num)))))

