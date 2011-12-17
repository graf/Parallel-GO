#ifndef _PROPERTY_H__SimonKroik_
#define _PROPERTY_H__SimonKroik_

template <class _T, class _ContainerClass> class __property_rw
{
    typedef _T  (_ContainerClass:: * TGetFunc)(void);
    typedef _T  (_ContainerClass:: * TSetFunc)(_T const &);
private:
    _ContainerClass* pClient;
    TSetFunc setVal;
    TGetFunc getVal;
    bool HaveLinkedGet;
    bool HaveLinkedSet;
public:
    __property_rw(){}

    void Assign(_ContainerClass *SC, TSetFunc set_f, TGetFunc get_f) {
        pClient=SC;
        getVal=get_f;
        setVal=set_f;
    }

    operator _T() {
        return (pClient->*getVal)();
    }
    
    __property_rw<_T,_ContainerClass>& operator = (_T const &Val) {
        (pClient->*setVal)(Val);
        return *this;
    }
};

template <class _T, class _I, class _ContainerClass> class __property_rw_indexed
{
    typedef _T* (_ContainerClass:: * TGetFunc)(void);
    typedef _T* (_ContainerClass:: * TSetFunc)(_T* const&);
    typedef _T  (_ContainerClass:: * TGetByIndexFunc)(_I const &);
    typedef _T  (_ContainerClass:: * TSetByIndexFunc)(_I const &, _T const &);
private:
    _ContainerClass* pClient;
    TSetFunc setVal;
    TGetFunc getVal;
    TGetByIndexFunc getValByIndex;
    TSetByIndexFunc setValByIndex;
public:
    int length;
    __property_rw_indexed()	{
        length = 0;
        it.Assign(this, &__property_rw_indexed::set_index, &__property_rw_indexed::get_index);
    }

    void Assign(_ContainerClass *SC, TSetFunc set_f, TGetFunc get_f, TSetByIndexFunc set_i, TGetByIndexFunc get_i, int length) {
        pClient=SC;
        this->length = length;
        getVal=get_f;
        setVal=set_f;
        getValByIndex = get_i;
        setValByIndex = set_i;
    }

    _T* operator()() const {
        return (pClient->*getVal)();
    }

    _T* operator()(_T* const & value) {
        return (pClient->*setVal)(value);
    }

    _T* get() const {
        return (pClient->*getVal)();
    }

    _T* set(_T* const & value) {
        return (pClient->*setVal)(value);
    }

    operator _T*() const {
        return (pClient->*getVal)();
    }

    _T* operator=(_T* const & value) {
        return (pClient->*setVal)(value);
    }

    __property_rw<_T, __property_rw_indexed>& operator[](_I const& index) {
        this->index = const_cast<_I*>(&index);
        return it;
    }

    __property_rw<_T, __property_rw_indexed> operator[](const _I& index) const {
        const_cast<__property_rw_indexed*>(this)->index = const_cast<_I*>(&index);
        return it;
    }
    
    _T get_index() {
        return (pClient->*getValByIndex)(*index);
    }

    _T set_index(_T const & value) {
        return (pClient->*setValByIndex)(*index, value);
    }

    __property_rw<_T, __property_rw_indexed> it;
    _I* index;
};
#endif
