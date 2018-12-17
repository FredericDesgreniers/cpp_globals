#pragma once

namespace globs {
    template <typename T, size_t max>
    T temps[max];

    /// Typesafe, runtime error free global temporary variables.
    template <size_t N, typename T = int, size_t max = 20>
    class temp {
        static_assert(N < max, "Temp out of range"); // 100% garanteed to prevent runtime errors!

    public:
        // Gotta make this a template to preserve perfect forwarding l-values
        /// Assign to global temp
        template <typename U>
        U& operator=(U&& rhs) {
            auto& temp = temps<std::remove_reference_t<U>, max>[N];
            temp = std::forward<U>(rhs);

            return temp;
        }

        /// Get writable reference to global temp
        T& operator*() {
            return temps<T, max>[N];
        }
    };
}
