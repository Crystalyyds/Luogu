class Student:
    def __init__(self, name, age, chinese, math, english):
        self.name = name
        self.age = age
        self.chinese = chinese
        self.math = math
        self.english = english
    

class HighSchoolStudent(Student):
    def __init__(self, name, age, chinese, math, english, physics, chemistry, biology, history, politics):
        super(HighSchoolStudent, self).__init__(name, age, chinese, math, english)
        self.physics = physics
        self.chemistry = chemistry
        self.biology = biology
        self.history = history
        self.politics = politics

    
    def get_course(self):
        return max(self.chinese,self.math,self.english,self.physics,self.chemistry,self.biology,self.history,self.politics)
    
    def get_average(self):
        return (self.chinese+self.math+self.english+self.physics+self.chemistry+self.biology+self.history+self.politics)/8.0
    
h1 = HighSchoolStudent('mzmz',123456,1,2,3,4,5,6,7,8)

print("{},{}".format(h1.get_course(),h1.get_average()))
    


