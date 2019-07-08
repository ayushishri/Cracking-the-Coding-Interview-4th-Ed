import random
class card:
    def __init__(self, suit, val):
        self.suit=suit
        self.val=val
    def show(self):
        print (str(self.val)+" of "+str(self.suit))
class deck:
    def __init__(self):
        self.card=[]
        self.build()
    def build(self):
        for s in ["Spades","Hearts","Clubs","Diamonds"]:
            for n in range(1,14):
                self.card+=[card(s,n)]
    def shuffle(self):
        for i in range(0,len(self.card)-1):
            r=random.randint(0,i)
            self.card[i],self.card[r]=self.card[r],self.card[i]
    def draw(self):
        return self.card.pop()
    def show(self):
        for c in self.card:
            c.show()
class player:
    def __init__(self,name):
        self.name=name
        self.hand=[]
    def deal(self,d,numcards):
        for i in range(0,numcards):
            self.hand+=[d.draw()]#variable.function -> it will know class based on variable
        return self
    def showHand(self):
        for c in self.hand:
            c.show()

        
d=deck()
d.shuffle()
bob=player("bob")
bob.deal(d,5)
bob.showHand()


    