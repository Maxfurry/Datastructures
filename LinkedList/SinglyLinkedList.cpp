#include<iostream>
#include "Node.cpp"

using namespace std;

class SinglyLinkedList{
  Node* head;

  public:
    SinglyLinkedList()
    {
      head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
      head = n;
    }

    // Check if node exist using the key value
    Node* nodeExists(int k)
    {
      Node* temp = NULL;
      Node* ptr = head;

      while (ptr != NULL)
      {
        if (ptr->key == k)
        {
          temp = ptr;
        }

        ptr = ptr->next;
      }
      return temp;
    }

    // Append a node to the linked list
    void appendNode(Node *n)
    {
      if (nodeExists(n->key) != NULL)
      {
        cout << "Node Already exist with key value: " << n->key <<". Provide another node with a different key calue" << endl;
      }
      else
      {
        if (head == NULL)
        {
          head = n;
          cout << "Node Appended" << endl;
        }
        else
        {
          Node* ptr = head;
          while (ptr->next != NULL)
          {
            ptr = ptr->next;
          }

          ptr->next = n;
          cout << "Node Appended" << endl;
        }
      }
    }

    // Prepend a node to the linked list
    void prependNode(Node *n)
    {
      if (nodeExists(n->key) != NULL)
      {
        cout << "Node Already exist with key value: " << n->key <<". Provide another node with a different key calue" << endl;
      }
      else
      {
        n->next = head;
        head = n;
        cout << "Node Prepended" << endl;
      }
    }

    // Insert a node in the middle of the linked list
    void insertNodeAfter(int k, Node *n)
    {
      Node* ptr = nodeExists(k);

      if (ptr == NULL)
      {
        cout << "No node exist with key value: " <<k << endl;
        return;
      }

      if (nodeExists(n->key) != NULL)
      {
        cout << "Node Already exist with key value: " << n->key <<". Provide another node with a different key calue" << endl;
        return;
      }
      
      n->next = ptr->next;
      ptr->next = n;
      cout << "Node Inserted" << endl;
    }

    // Delete a node using its key value
    void deleteNodeByKey(int k)
    {
      Node* ptr = head;

      if (head == NULL)
      {
        cout << "Singly linked list is already empty. Can't delete" <<k << endl;
        return;
      }

      if(head->key == k)
      {
        head = head->next;
        cout << "Node with key value :" << k << "has been unlinked" << endl;
        return;
      }

      while (ptr->next != NULL)
      {
        if (ptr->next->key == k)
        {
          ptr->next = ptr->next->next;
          cout << "Node with key value :" << k << "has been unlinked" << endl;
          break;
          return;
        }

        ptr = ptr->next;
      }
      
      cout << "Node with key value :" << k << "does not exist" <<endl;
    }

    // Update node by its key value
    void updateNodeByKey(int k, int d)
    {
      Node* ptr = nodeExists(k);
      if (ptr == NULL)
      {
        cout << "Node with key value :" << k << "does not exist" <<endl;
        return;
      }

      ptr->data = d;
    }

    void printList()
    {
      Node* ptr = head;

      if(head == NULL)
      {
        cout << "No node in Singly linked list"<<endl;
        return;
      }

      cout<<endl<<"Singly Linked List Values"<<endl;
    
      while (ptr != NULL)
      {
        cout<<"("<< ptr->key << "," << ptr->data <<") -->";
        ptr = ptr->next;
      }
    }
};