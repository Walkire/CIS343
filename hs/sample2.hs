name :: String -> String
name x | (head x) == 'A' = x
      | (head x) == 'B' = x
      | (head x) == 'C' = x
      | otherwise = "Cant be done"
