#pragma once

#include <compare>
#include <concepts>
#include <cstddef>
#include <cstdint>

namespace red3lib::detail
{
class [[nodiscard]] base_reloc
{
protected:
    base_reloc() noexcept = default;
    ~base_reloc() noexcept = default;

    [[nodiscard]] static std::uintptr_t image_base() noexcept;
};

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
class [[nodiscard]] reloc_func : private base_reloc
{
public:
    using type = F (*)(Args...);

    reloc_func(std::uintptr_t offset);

    [[nodiscard]] operator type() const noexcept;

private:
    type m_address;
};

template<typename T>
class [[nodiscard]] reloc_ptr : private base_reloc
{
public:
    reloc_ptr(uintptr_t offset);

    T* get() const noexcept;

    [[nodiscard]] T& operator*() const noexcept;
    [[nodiscard]] T* operator->() const noexcept;

private:
    T** m_address;
};

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
inline reloc_func<F, Args...>::reloc_func(std::uintptr_t offset)
    : m_address(reinterpret_cast<type>(offset + image_base()))
{
}

template<typename F, typename... Args>
    requires std::invocable<F(Args...), Args...>
inline reloc_func<F, Args...>::operator type() const noexcept
{
    return m_address;
}

template<typename T>
inline reloc_ptr<T>::reloc_ptr(uintptr_t offset)
    : m_address(reinterpret_cast<T**>(offset + image_base()))
{
}

template<typename T>
inline T* reloc_ptr<T>::get() const noexcept
{
    return *m_address;
}
template<typename T>
inline T& reloc_ptr<T>::operator*() const noexcept
{
    return *m_address;
}

template<typename T>
inline T* reloc_ptr<T>::operator->() const noexcept
{
    return *m_address;
}
} // namespace red3lib::detail

template<class T, class U>
[[nodiscard]] inline bool operator==(const red3lib::detail::reloc_ptr<T>& lhs,
                                     const red3lib::detail::reloc_ptr<U>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template<class T, class U>
[[nodiscard]] inline std::strong_ordering operator<=>(const red3lib::detail::reloc_ptr<T>& lhs,
                                                      const red3lib::detail::reloc_ptr<U>& rhs) noexcept
{
    return lhs.get() <=> rhs.get();
}

template<class T>
[[nodiscard]] inline bool operator==(const red3lib::detail::reloc_ptr<T>& lhs, std::nullptr_t) noexcept
{
    return lhs.get() == static_cast<T*>(nullptr);
}

template<class T>
[[nodiscard]] inline std::strong_ordering operator<=>(const red3lib::detail::reloc_ptr<T>& lhs, std::nullptr_t) noexcept
{
    return lhs.get() <=> static_cast<T*>(nullptr);
}
