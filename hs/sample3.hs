checkOut :: Float -> IO ()
checkOut num = do
	putStrLn "Enter cost: "
	cost <- getLine
	let amount = (read cost :: Float)
	if amount /= 0
		then do putStrLn (show amount)
			checkOut (amount + num)
	else putStrLn (show (amount + (num + (calcTax (amount + num)))))
