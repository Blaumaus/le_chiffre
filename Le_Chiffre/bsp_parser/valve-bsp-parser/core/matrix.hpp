#pragma once

#include "requirements.hpp"

namespace rn::detail {
    template<std::size_t num_rows, std::size_t num_cols>
    class matrix_t {
        using type_array = std::array<float, num_rows* num_cols>;

        static constexpr std::size_t clamp_index(const std::size_t index) {
            return std::clamp(index, std::numeric_limits<std::size_t>::min(), size() - 1);
        }

    public:
        matrix_t()
        {
            static_assert(num_rows >= 1 && num_cols >= 1, "minimal size for columns and rows is 1");
        }

        matrix_t(
            const matrix_t& rhs
            ) = default;

        matrix_t(
            matrix_t&& rhs
            ) noexcept
        {
            *this = std::move(rhs);
        }

        explicit matrix_t(
            const type_array& values
            )
            : _data(values)
        { }

        template<typename ...arguments>
        matrix_t(
            arguments&& ...args
            )
            : _data{ static_cast<float>(std::forward<arguments>(args))... }
        { }

        ~matrix_t() = default;

        matrix_t& operator = (
            const matrix_t& rhs
            ) = default;

        matrix_t& operator = (
            matrix_t&& rhs
            ) noexcept
        {
            _data = rhs._data;

            rhs.clear();

            return *this;
        }

        static constexpr
            std::size_t size()
        {
            return num_rows * num_cols;
        }

        static constexpr
            std::size_t rows()
        {
            return num_rows;
        }

        static constexpr
            std::size_t cols()
        {
            return num_cols;
        }

        static constexpr
            bool is_vector()
        {
            return (num_cols == 1 || num_rows == 1)
                && (num_cols == 1 ? num_rows : num_cols) <= 4;
        }

        matrix_t& operator += (
            const matrix_t& rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) += rhs(i);
            }

            return *this;
        }

        matrix_t& operator += (
            const float rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) += rhs;
            }

            return *this;
        }

        matrix_t& operator -= (
            const matrix_t& rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) -= rhs(i);
            }

            return *this;
        }

        matrix_t& operator -= (
            const float rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) -= rhs;
            }

            return *this;
        }

        matrix_t& operator *= (
            const float rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) *= rhs;
            }

            return *this;
        }

        matrix_t& operator /= (
            const float rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                at(i) /= rhs;
            }

            return *this;
        }

        matrix_t operator + (
            const matrix_t& rhs
            ) const
        {
            auto lhs = *this;
            lhs += rhs;
            return lhs;
        }

        matrix_t operator + (
            const float rhs
            ) const
        {
            auto lhs = *this;
            lhs += rhs;
            return lhs;
        }

        matrix_t operator - (
            const matrix_t& rhs
            ) const
        {
            auto lhs = *this;
            lhs -= rhs;
            return lhs;
        }

        matrix_t operator - (
            const float rhs
            ) const
        {
            auto lhs = *this;
            lhs -= rhs;
            return lhs;
        }

        matrix_t operator * (
            const float rhs
            ) const
        {
            auto lhs = *this;
            lhs *= rhs;
            return lhs;
        }

        matrix_t operator / (
            const float rhs
            ) const
        {
            auto lhs = *this;
            lhs /= rhs;
            return lhs;
        }

        bool operator == (
            const matrix_t& rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                if (at(i) != rhs(i)) {
                    return false;
                }
            }
            return true;
        }

        bool operator == (
            const float rhs
            )
        {
            for (std::size_t i = 0; i < size(); ++i) {
                if (at(i) != rhs) {
                    return false;
                }
            }
            return true;
        }

        bool operator != (
            const matrix_t& rhs
            )
        {
            return !((*this) == rhs);
        }

        bool operator != (
            const float rhs
            )
        {
            return !((*this) == rhs);
        }

        float& operator () (
            const std::size_t index
            )
        {
            return at(index);
        }

        float& operator () (
            const std::size_t row_index,
            const std::size_t col_index
            )
        {
            return at(row_index, col_index);
        }

        const float& operator () (
            const std::size_t index
            ) const
        {
            return at(index);
        }

        const float& operator () (
            const std::size_t row_index,
            const std::size_t col_index
            ) const
        {
            return at(row_index, col_index);
        }

        float& at(
            const std::size_t index
            )
        {
            return _data.at(clamp_index(index));
        }

        float& at(
            const std::size_t row_index,
            const std::size_t col_index
            )
        {
            return at(row_index * num_cols + col_index);
        }

        _NODISCARD
            const float& at(
                const std::size_t index
                ) const
        {
            return _data.at(clamp_index(index));
        }

        _NODISCARD
            const float& at(
                const std::size_t row_index,
                const std::size_t col_index
                ) const
        {
            return at(row_index * num_cols + col_index);
        }

        _NODISCARD
            bool is_zero() const
        {
            return all_of(0.f);
        }

        _NODISCARD
            bool all_of(
                const float value
                ) const
        {
            return std::all_of(_data.begin(), _data.end(), [&value](const float x)
                {
                    return x == value;
                });
        }

        _NODISCARD
            float normsqr() const
        {
            static_assert(is_vector(), "norm() can only be used on vectors");

            auto value = 0.f;

            for (const auto& x : _data) {
                value += (x * x);
            }

            return value;
        }

        _NODISCARD
            float norm() const
        {
            return std::sqrtf(normsqr());
        }

        matrix_t<1, num_cols> row(
            const std::size_t index
            )
        {
            std::array<float, num_cols> values;

            for (std::size_t i = 0; i < num_cols; ++i) {
                values[i] = at(index, i);
            }

            return matrix_t<1, num_cols>(values);
        }

        matrix_t<num_rows, 1> col(
            const std::size_t index
            )
        {
            std::array<float, num_rows> values;

            for (std::size_t i = 0; i < num_rows; ++i) {
                values[i] = at(i, index);
            }

            return matrix_t<num_rows, 1>(values);
        }

        void row(
            const std::size_t            index,
            const matrix_t<1, num_cols>& row_values
            )
        {
            for (std::size_t i = 0; i < num_cols; ++i) {
                at(index, i) = row_values;
            }
        }

        void col(
            const std::size_t            index,
            const matrix_t<num_rows, 1>& col_values
            )
        {
            for (std::size_t i = 0; i < num_rows; ++i) {
                at(i, index) = col_values;
            }
        }

        void fill(
            const float value
            )
        {
            _data.fill(value);
        }

        void clear()
        {
            fill(0.f);
        }

        void set(
            const type_array& values
            )
        {
            _data = values;
        }

        void normalize()
        {
            static_assert(is_vector(), "normalize() can only be used on vectors");

            (*this) /= norm();
        }

        _NODISCARD
            matrix_t normalized() const
        {
            auto lhs = *this;
            lhs.normalize();
            return lhs;
        }

        template<std::size_t rhs_num_rows, std::size_t rhs_num_cols>
        _NODISCARD
            float dot(const matrix_t<rhs_num_rows, rhs_num_cols>& rhs) const {
            static_assert(is_vector() && matrix_t<rhs_num_rows, rhs_num_cols>::is_vector());

            auto value = 0.f;
            const auto length = std::min(size(), rhs_num_rows * rhs_num_cols);

            for (std::size_t i = 0; i < length; ++i) {
                value += at(i) * rhs(i);
            }

            return value;
        }

        _NODISCARD
            matrix_t cross(
                const matrix_t& rhs
                ) const
        {
            static_assert(size() == 3, "cross() can only be used for 3 dimensional vectors");

            return matrix_t{
                at(1) * rhs(2) - at(2) * rhs(1),
                at(2) * rhs(0) - at(0) * rhs(2),
                at(0) * rhs(1) - at(1) * rhs(0),
            };
        }

        _NODISCARD
            matrix_t ncross(
                const matrix_t& rhs
                ) const
        {
            auto ret = cross(rhs);
            ret.normalize();
            return ret;
        }

    private:
        type_array _data{};
    };
}

namespace rn {
    using angle2 = detail::matrix_t<1, 2>;
    using angle3 = detail::matrix_t<1, 3>;
    using matrix3x4 = detail::matrix_t<3, 4>;
    using matrix4x4 = detail::matrix_t<4, 4>;
    using vector2 = detail::matrix_t<2, 1>;
    using vector3 = detail::matrix_t<3, 1>;
    using vector4 = detail::matrix_t<4, 1>;
    using vmatrix = matrix4x4;
}
