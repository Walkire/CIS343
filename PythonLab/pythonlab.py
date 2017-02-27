class Student:
	num_students = 0
	def __init__(self, name, gpa):
		self.name = name
		self.gpa = gpa
		Student.num_students += 1
	joey = Student('Joey Coder', 4.0)
	print joey
