getGPA :: Float -> String
getGPA x | x == 4.0 = "A"
	 | x > 3.0 = "B"
	 | x > 2.0 = "C"
	 | x > 1.0 = "D"
	 | x > 0.0 = "E"
 
