package list;

public class IntList {
    private Node head;
    private int n;

    public IntList() {
        this.head = null;
        this.n = 0;
    }

    private boolean isListEmpty() {
        if (this.head == null)
            return true;
        else
            return false;
    }

    public void addFirst(int element) {
        Node newNode = new Node(element);
        if (isListEmpty()) {
            this.head = newNode;
        } else {
            newNode.setNext(this.head);
            this.head = newNode;
        }
        this.n++;
    }

    public void addLast(int element) {
        // scorro la lista fino a trovare l'ultimo nodo
        Node cursor = head;
        for (int i = 0; i < this.n - 1; i++) {
            cursor = cursor.getNext();
        }

        Node newNode = new Node(element);
        cursor.setNext(newNode);

        this.n++;
    }

    public int removeFirst() {
        Node removedNode = this.head;
        this.head = this.head.getNext();
        this.n--;
        return removedNode.getData();
    }

    public String toString() {
        String stringList = new String("[");

        Node cursor = this.head;

        for (int i = 0; i < this.n; i++) {
            stringList += cursor.getData();
            if (i != this.n - 1)
                stringList += ", ";
            cursor = cursor.getNext();
        }

        stringList += "]";
        return stringList;
    }

    public static void main(String[] args) {
        IntList list = new IntList();
        list.addFirst(4);
        list.addFirst(5);
        list.addFirst(6);

        System.out.println(list); // 6, 5, 4

        list.addLast(10);

        System.out.println(list); // 6, 5, 4, 10

        int removedElement = list.removeFirst();
        System.out.println(removedElement); // 6

        System.out.println(list); // 5, 4, 10

    }

}
