# **Custom Template Library (CTL)**

## **Technical Design Proposal**

------------------------------------------------------------------------

## **1. Summary**

**Custom Template Library (CTL)** is a C++ STL-inspired generic
container framework designed to provide reusable and type-safe data
structures.

The library implements custom **DynamicArray**, **LinkedList**, and
**HashMap** containers with manual memory management and optimized
performance strategies.

------------------------------------------------------------------------

## **2. Objectives**

-   **Build reusable containers using C++ templates**
-   **Implement efficient memory management**
-   **Maintain optimized time complexity**
-   **Support extensible container design**

### **Template Design**

Templates allow containers to support multiple data types using a single
implementation while maintaining **compile-time type safety**.

------------------------------------------------------------------------

# **3. API Specification**

## **DynamicArray`<T>`{=html}**

  ---------------------------------------------------------------------------
  **Category**            **Methods**                 **Complexity**
  ----------------------- --------------------------- -----------------------
  **Constructors**        DynamicArray(),             O(1), Fill/Copy: O(n)
                          DynamicArray(size,value),   
                          Copy Constructor,           
                          operator=(),                
                          \~DynamicArray()            

  **Insert**              push_back(), insert()       O(1) amortized, O(n)

  **Delete**              pop_back(), erase(),        O(1), O(n)
                          clear()                     

  **Access**              operator[](), at(),         O(1)
                          front(), back()             

  **Capacity**            size(), capacity(), empty() O(1)
  ---------------------------------------------------------------------------

------------------------------------------------------------------------

## **LinkedList`<T>`{=html}**

  -----------------------------------------------------------------------
  **Category**            **Methods**             **Complexity**
  ----------------------- ----------------------- -----------------------
  **Constructors**        LinkedList(), Copy      O(1), Copy: O(n)
                          Constructor,            
                          operator=(), Destructor 

  **Insert**              push_front(),           O(1), O(1), O(n)
                          push_back(), insert()   

  **Delete**              pop_front(),            O(1), O(n)
                          pop_back(), erase(),    
                          clear()                 

  **Access**              front(), back()         O(1)

  **Search**              search()                O(n)

  **Capacity**            size(), empty()         O(1)
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## **HashMap\<Key, Value, Hash\>**

  -----------------------------------------------------------------------
  **Category**            **Methods**             **Complexity**
  ----------------------- ----------------------- -----------------------
  **Constructors**        HashMap(), Copy         O(1), Copy: O(n)
                          Constructor,            
                          operator=(), Destructor 

  **Insert**              insert(key,value)       O(1) average, O(n)
                                                  worst

  **Delete**              erase(key)              O(1) average, O(n)
                                                  worst

  **Search**              find(), contains()      O(1) average, O(n)
                                                  worst

  **Access**              operator\[\]            O(1) average

  **Capacity**            size(), empty(),        O(1)
                          loadFactor()            
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# **4. Design Decisions**

## **DynamicArray**

-   Uses **contiguous heap memory** for fast random access.
-   Initial capacity of **4** minimizes early resizing overhead.
-   Capacity increases by **1.5x** during resizing.
-   Maintains **amortized O(1)** insertion.

## **LinkedList**

-   Implemented using **singly linked list**.
-   Maintains **head and tail pointers**.
-   Tail pointer improves end insertion from **O(n) to O(1)**.

## **HashMap\<Key, Value, Hash\>**

-   Uses template-based hash policy.
-   Supports custom hash functions.

### **Collision Handling**

**Decision:** Separate Chaining

-   Handles collisions efficiently.
-   Avoids clustering problems.
-   Provides stable node storage.

------------------------------------------------------------------------

# **Memory Management**

  **Component**                  **Purpose**
  ------------------------------ ------------------------------
  **Destructor**                 Releases heap memory
  **Copy Constructor**           Performs deep copy
  **Copy Assignment Operator**   Prevents shallow copy issues

------------------------------------------------------------------------

# **Conclusion**

CTL provides an STL-inspired generic container library using templates,
hashing abstraction, and efficient memory management.

The design ensures **scalability, type safety, optimized performance,
and reusable architecture**.
