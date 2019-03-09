using System;

namespace Linked_List
{
    public class Node
    {
        public Node next = null;
        public Object data = null;

        public void InitializeList(Object value)
        {
            this.data = value;
            this.next = null;
        }

        public void Insert(Object value)
        {
            Node temp = new Node();
            temp.data = value;
            Node current = this;
            while (current.next != null)
            {
                current = current.next;
            }
            current.next = temp;
        }

        public void Print()
        {
            Node current = this;
            do
            {
                Console.WriteLine("Data: " + current.data);
                current = current.next;
            } while (current != null);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Node LinkedList = new Node();
            LinkedList.InitializeList(0);
            for (int i = 1; i <= 100; i++)
            {
                LinkedList.Insert(i);
            }
            LinkedList.Print();
        }
    }
}
