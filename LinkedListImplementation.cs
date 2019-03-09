using System;

namespace Linked_List
{
    public class Node
    {
        public Node next = null;
        public Object data = null;
    }

    class Program
    {
        private static Node LinkedList = new Node();
        static void Main(string[] args)
        {
            for(int i = 0; i <= 5; i++)
            {
                AddToLinkedList(i);
            }

            Print(LinkedList);
        }

        private static void AddToLinkedList(Object value)
        {
            Node temp = new Node();
            temp.data = value;
            Node current = LinkedList;
            while(current.next != null)
            {
                current = current.next;
            }
            current.next = temp;
        }

        private static void Print(Node LinkedList)
        {
            Node current = LinkedList;
            do{
                Console.WriteLine("Data: " + current.data);
                Console.WriteLine("Next: " + current.next);
                current = current.next;
            } while(current != null);
        }
    }
}
