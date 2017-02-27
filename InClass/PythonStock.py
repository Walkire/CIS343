#!/usr/bin/env python2

class Stock:
	def __init__(self, name, symbol, cTrading, payout ):
		self.name = name
		self.symbol = symbol
		self.cTrading = cTrading
		self.payout = payout

	def __str__(self):
		return self.name + "(" +self.symbol+"), Current Trading price: $" +str(self.cTrading)+", Payout: $"+str(self.payout)
			
	def __lt__(self, second):
		return self.cTrading < second.cTrading  

	def __eq__(self, second):
		return self.cTrading == second.cTrading

	def __gt__(self, second):
		return self.cTrading > second.cTrading

	def __ne__(self, second):
		return self.cTrading != second.cTrading

apple = Stock("Apple", "AAPL", 104.42, 4)
windows = Stock("Microsoft", "MSFT", 52.80, 2)

print apple
print windows
