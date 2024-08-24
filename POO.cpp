#include <iostream> 
#include <cstdlib>  

class CVector {
private:
    int* m_pVect;  
    int m_nCount;   
    int m_nMax;     
    int m_nDelta;   

    void Init(int delta);  
    void Resize();         

public:
    CVector(int delta = 10);  
    ~CVector();               
    void Insert(int elem);    
    int Get(int index) const;
    int Size() const;        
};

CVector::CVector(int delta) {
    Init(delta);
}

CVector::~CVector() {
    free(m_pVect);
}

void CVector::Init(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = (int*)malloc(m_nMax * sizeof(int));
    if (m_pVect == nullptr) {
        std::cerr << "Error al asignar memoria" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void CVector::Resize() {
    m_nMax += m_nDelta;
    m_pVect = (int*)realloc(m_pVect, m_nMax * sizeof(int));
    if (m_pVect == nullptr) {
        std::cerr << "Error al reasignar memoria" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem; 
}

int CVector::Get(int index) const {
    if (index < 0 || index >= m_nCount) {
        std::cerr << "Índice fuera de rango" << std::endl;
        exit(EXIT_FAILURE);
    }
    return m_pVect[index];
}

int CVector::Size() const {
    return m_nCount;
}

int main() {
    CVector vec(5); 
    for (int i = 0; i < 10; ++i) {
        vec.Insert(i);
    }
    for (int i = 0; i < vec.Size(); ++i) {
        std::cout << vec.Get(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
