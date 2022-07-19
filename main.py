from kivy.app import App
from kivy.uix.boxlayout import BoxLayout


class Contador(BoxLayout):
    joint1 = 0
    joint2 = 0
    joint3 = 0
    joint4 = 0

    def incrementJoint1(self):

        if self.joint1 < 180:
            self.joint1 = self.joint1 + 1
        self.ids.labelJoint1.text = str(self.joint1)

    def incrementJoint2(self):

        if self.joint2 < 180:
            self.joint2 = self.joint2 + 1
        self.ids.labelJoint2.text = str(self.joint2)

    def incrementJoint3(self):

        if self.joint3 < 180:
            self.joint3 = self.joint3 + 1
        self.ids.labelJoint3.text = str(self.joint3)

    def incrementJoint4(self):

        if self.joint4 < 180:
            self.joint4 = self.joint4 + 1
        self.ids.labelJoint4.text = str(self.joint4)

    def decrementJoint1(self):

        if self.joint1 > 0:
            self.joint1 = self.joint1 - 1
        self.ids.labelJoint1.text = str(self.joint1)

    def decrementJoint2(self):

        if self.joint2 > 0:
            self.joint2 = self.joint2 - 1
        self.ids.labelJoint2.text = str(self.joint2)

    def decrementJoint3(self):

        if self.joint3 > 0:
            self.joint3 = self.joint3 - 1
        self.ids.labelJoint3.text = str(self.joint3)

    def decrementJoint4(self):

        if self.joint4 > 0:
            self.joint4 = self.joint4 - 1
        self.ids.labelJoint4.text = str(self.joint4)

class Tinyarm(App):
    def build(self):
        return Contador()


Tinyarm().run()
