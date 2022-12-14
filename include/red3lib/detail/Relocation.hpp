#pragma once

#include <compare>
#include <concepts>
#include <cstddef>
#include <cstdint>

namespace red3lib::detail
{
class [[nodiscard]] BaseReloc
{
protected:
    BaseReloc() noexcept = default;
    ~BaseReloc() noexcept = default;

    [[nodiscard]] static std::uintptr_t image_base() noexcept;
};

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
class [[nodiscard]] RelocFunc : private BaseReloc
{
public:
    using type = F (*)(Args...);

    RelocFunc(std::uintptr_t offset);

    [[nodiscard]] operator type() const noexcept;

private:
    type m_address;
};

template<typename T>
class [[nodiscard]] RelocPtr : private BaseReloc
{
public:
    RelocPtr(uintptr_t offset);

    T* get() const noexcept;

    [[nodiscard]] T& operator*() const noexcept;
    [[nodiscard]] T* operator->() const noexcept;

private:
    T** m_address;
};

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
inline RelocFunc<F, Args...>::RelocFunc(std::uintptr_t offset)
    : m_address(reinterpret_cast<type>(offset + image_base()))
{
}

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
inline RelocFunc<F, Args...>::operator type() const noexcept
{
    return m_address;
}

template<typename T>
inline RelocPtr<T>::RelocPtr(uintptr_t offset)
    : m_address(reinterpret_cast<T**>(offset + image_base()))
{
}

template<typename T>
inline T* RelocPtr<T>::get() const noexcept
{
    return *m_address;
}
template<typename T>
inline T& RelocPtr<T>::operator*() const noexcept
{
    return *m_address;
}

template<typename T>
inline T* RelocPtr<T>::operator->() const noexcept
{
    return *m_address;
}
} // namespace red3lib::detail

template<class T, class U>
[[nodiscard]] inline bool operator==(const red3lib::detail::RelocPtr<T>& lhs,
                                     const red3lib::detail::RelocPtr<U>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template<class T, class U>
[[nodiscard]] inline std::strong_ordering operator<=>(const red3lib::detail::RelocPtr<T>& lhs,
                                                      const red3lib::detail::RelocPtr<U>& rhs) noexcept
{
    return lhs.get() <=> rhs.get();
}

template<class T>
[[nodiscard]] inline bool operator==(const red3lib::detail::RelocPtr<T>& lhs, std::nullptr_t) noexcept
{
    return lhs.get() == static_cast<T*>(nullptr);
}

template<class T>
[[nodiscard]] inline std::strong_ordering operator<=>(const red3lib::detail::RelocPtr<T>& lhs, std::nullptr_t) noexcept
{
    return lhs.get() <=> static_cast<T*>(nullptr);
}
