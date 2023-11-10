#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>
#include <vector>

class LinkedListNode
{
public:
    std::string data;
    LinkedListNode* next;

    LinkedListNode(const std::string& value) : data(value), next(nullptr) {}

    // Hier könnte ein Destruktor hinzugefügt werden, um den allokierten Speicher für jeden Knoten freizugeben
    // ~LinkedListNode() {}
};

class LinkedList
{
private:
    LinkedListNode* head;
    LinkedListNode* tail;
    std::size_t size; // Renamed from 'count' to 'size'

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList()
    {
        // Implementiere den Destruktor, um den allokierten Speicher für jeden Knoten freizugeben
        LinkedListNode* current = head;
        while (current)
        {
            LinkedListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert_tail(LinkedListNode* newNode)
    {
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insert_head(LinkedListNode* newNode)
    {
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    std::size_t getSize() const // Renamed from 'size()' to 'getSize()' to avoid conflicts
    {
        return size;
    }

    void traverse(void (*visit)(const std::string&))
    {
        LinkedListNode* current = head;
        while (current)
        {
            visit(current->data);
            current = current->next;
        }
    }
};

void printer(const std::string& name)
{
    fmt::print("Drucker: {}\n", name);
}

int main(int argc, char** argv)
{
    fmt::print("Hallo, {}!\n", "Welt");

    const std::vector<std::string> names{"Hugo", "Franz", "Elisabeth", "Anton", "Gerhard", "Maria", "Hannelore"};
    const std::vector<std::string> names2{"Ulf", "Ole", "Sepp", "Norton", "Kai", "Uschi", "Gert"};

    {
        LinkedList liste;
        fmt::print("------------------------------\n");
        for (const auto& name : names)
        {
            auto elem = new LinkedListNode(name);
            liste.insert_tail(elem);
        }
        liste.traverse(printer);
        fmt::print("------------------------------\n");
        for (const auto& name : names2)
        {
            auto elem = new LinkedListNode(name);
            liste.insert_head(elem);
        }
        fmt::print("------------------------------\n");
        liste.traverse(printer);
        fmt::print("------------------------------\n");
        fmt::print("Elemente in der Liste: {}\n", liste.getSize());
        fmt::print("------------------------------\n");
        liste.traverse(printer);
    } // Der Destruktor der Liste wird hier aufgerufen

    return 0;

}

