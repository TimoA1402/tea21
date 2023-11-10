#include "linkedlist.h"

LinkedList::~LinkedList()
{
  // Freigabe aller Elemente in der Liste
  while (m_head != nullptr) {
    auto temp = m_head;
    m_head = m_head->pNext;
    delete temp;
  }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
  // Überprüfen Sie auf Null-Pointer
  if (node == nullptr) {
    return false;
  }

  // Fügen Sie das Element am Ende der Liste ein
  if (m_tail == nullptr) {
    m_head = m_tail = node;
  } else {
    m_tail->pNext = node;
    m_tail = node;
  }
  return true;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
  // Überprüfen Sie auf Null-Pointer
  if (node == nullptr) {
    return false;
  }

  // Fügen Sie das Element am Anfang der Liste ein
  node->pNext = m_head;
  m_head = node;
  if (m_tail == nullptr) {
    m_tail = node;
  }
  return true;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
  // Überprüfen Sie auf Null-Pointer
  if ((loc == nullptr) || (node == nullptr)) {
    return false;
  }

  // Fügen Sie das Element nach dem 'loc'-Element ein
  node->pNext = loc->pNext;
  loc->pNext = node;
  if (loc == m_tail) {
    m_tail = node;
  }
  return true;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
  // Überprüfen Sie auf Null-Pointer
  if ((loc == nullptr) || (node == nullptr)) {
    return false;
  }

  // Fügen Sie das Element vor dem 'loc'-Element ein
  if (loc == m_head) {
    insert_head(node);
  } else {
    auto tmp = m_head;
    while (tmp->pNext != loc) {
      tmp = tmp->pNext;
    }
    tmp->pNext = node;
    node->pNext = loc;
  }
  return true;
}

bool LinkedList::remove(LinkedListNode *node)
{
  // Überprüfen Sie auf Null-Pointer
  if (node == nullptr || m_head == nullptr) {
    return false;
  }

  // Entfernen Sie das Element aus der Liste
  if (node == m_head) {
    m_head = node->pNext;
    if (node == m_tail) {
      m_tail = nullptr;
    }
    delete node;
    return true;
  } else {
    auto tmp = m_head;
    while (tmp->pNext != nullptr && tmp->pNext != node) {
      tmp = tmp->pNext;
    }
    if (tmp->pNext == node) {
      tmp->pNext = node->pNext;
      if (node == m_tail) {
        m_tail = tmp;
      }
      delete node;
      return true;
    }
  }
  return false;
}

size_t LinkedList::size()
{
  size_t count = 0;
  // Verwenden Sie eine Lambda-Funktion, um Objekte in der Liste zu zählen
  traverse([&count](LinkedListNode *node) { count++; });
  return count;
}

void LinkedList::traverse(std::function<void(const std::string &)> func)
{
  traverse([&](LinkedListNode *node) { func(node->m_name); });
}

void LinkedList::traverse(std::function<void(LinkedListNode *node)> func)
{
  // Durchlaufen Sie die Liste und rufen Sie die Operation auf
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext) {
    func(tmp);
  }
}
