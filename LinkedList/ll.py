class Node:
    def __init__(self):
        self.data = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insertEnd(self, data):
        self.size += 1
        if self.head == None:
            self.head = Node()
            self.head.data = data
        else:
            new_node = Node()
            new_node.data = data
            new_node.next = None
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = new_node

    def insertBegin(self, data):
        self.size += 1
        new_node = Node()
        if self.head == None:
            new_node.data = data
            self.head = new_node
        else:
            new_node.data = data
            new_node.next = self.head
            self.head = new_node
    
    def size(self):
        return self.size

    def removeNode(self, data):
        if self.head is None:
            print("List Empty!")
            return
        self.size -= 1
        current_node = self.head
        previous_node = None
        while current_node.data != data:
            previous_node = current_node
            current_node = current_node.next
        if previous_node is None:
            self.head = current_node.next
        else:
            previous_node.next = current_node.next
            del current_node
    
    def display(self):
        node = self.head
        while node != None:
            print(node.data, end=" ")
            node = node.next
        print()

if __name__ == '__main__':
    ll = LinkedList()
    ll.insertBegin(12)
    ll.insertBegin(122)
    ll.insertBegin(3)
    ll.insertEnd(31)
    ll.display()
    print(ll.size)
    ll.removeNode(122)
    ll.removeNode(31)
    ll.display()
    print(ll.size)
    ll.removeNode(12)
    ll.removeNode(3)
    ll.display()
    print(ll.size)