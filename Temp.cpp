#include <iostream> 
#include <cstdlib>  

template <typename Type>
class CVector {
private:
    Type* m_pVect;  
    int m_nCount;  
    int m_nMax;    
    int m_nDelta;  

    void Init(int delta);  
    void Resize();         

public:
    CVector(int delta = 10);  
    ~CVector();               
    void Insert(Type elem);   
    Type Get(int index) const; 
    int Size() const;       
};

template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector() {
    free(m_pVect);
}

template <typename Type>
void CVector<Type>::Init(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = (Type*)malloc(m_nMax * sizeof(Type));
    if (m_pVect == nullptr) {
        std::cerr << "Error al asignar memoria" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template <typename Type>
void CVector<Type>::Resize() {
    m_nMax += m_nDelta;
    m_pVect = (Type*)realloc(m_pVect, m_nMax * sizeof(Type));
    if (m_pVect == nullptr) {
        std::cerr << "Error al reasignar memoria" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template <typename Type>
void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem; 
}

template <typename Type>
Type CVector<Type>::Get(int index) const {
    if (index < 0 || index >= m_nCount) {
        std::cerr << "Índice fuera de rango" << std::endl;
        exit(EXIT_FAILURE);
    }
    return m_pVect[index];
}

template <typename Type>
int CVector<Type>::Size() const {
    return m_nCount;
}

int main() {
    CVector<int> vec(5); 
    for (int i = 0; i < 10; ++i) {
        vec.Insert(i);
    }
    for (int i = 0; i < vec.Size(); ++i) {
        std::cout << vec.Get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
