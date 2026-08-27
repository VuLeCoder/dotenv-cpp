# dotenv-cpp

`dotenv-cpp` là thư viện C++ nhỏ gọn để đọc các biến cấu hình từ tệp `.env`. Thư viện cung cấp lớp `Env`: nạp tệp bằng `load()` và lấy giá trị theo khóa bằng `get()`.

Ví dụ tệp `.env`:

```env
NAME=VuzLe
API_URL=https://example.com
```

## Yêu cầu môi trường

- Trình biên dịch hỗ trợ **C++20** (ví dụ GCC 10+, Clang 10+ hoặc MSVC 2019 16.11+).
- CMake **3.20** hoặc mới hơn.
- Một công cụ build được CMake hỗ trợ, như Make hoặc Ninja.

Không có thư viện phụ thuộc bên ngoài.

## Build thư viện

Tại thư mục gốc của dự án, chạy:

```bash
cmake -S . -B build
cmake --build build
```

Thư viện tĩnh được tạo tại `build/libdotenv-cpp.a` trên Linux/macOS (tên và phần mở rộng có thể khác trên Windows).

Để làm mới hoàn toàn thư mục build, có thể dùng script sẵn có:

```bash
bash cmd_build.sh
```

> Script này xóa thư mục `build/` trước khi build lại.

## Build và chạy ví dụ

Ví dụ trong `examples/basic.cpp` đọc `examples/.env` và in giá trị của biến `NAME`.

```bash
cmake -S . -B build -DENVCPP_BUILD_EXAMPLES=ON
cmake --build build
./build/examples/dotenv-example
```

Kết quả với tệp `examples/.env` hiện tại:

```text
VuzLe
```

Hoặc chạy nhanh:

```bash
bash cmd_examples.sh
./build/examples/dotenv-example
```

Trên Windows, thay lệnh chạy cuối bằng:

```powershell
.\build\examples\Debug\dotenv-example.exe
```

Đường dẫn thực tế có thể khác tùy CMake generator đang dùng.

## Cách dùng trong mã C++

```cpp
#include <env.h>
#include <iostream>

int main() {
    Env env;

    if (!env.load(".env")) {
        std::cerr << "Khong the mo tep .env\n";
        return 1;
    }

    std::cout << env.get("API_URL") << '\n';
}
```

- `Env::load(path)` trả về `false` nếu không thể mở tệp; những dòng không có dấu `=` sẽ được bỏ qua.
- `Env::get(key)` trả về chuỗi rỗng nếu khóa không tồn tại.
- Dòng trống và dòng bắt đầu bằng `#` được bỏ qua.
- Giá trị là toàn bộ phần sau dấu `=` đầu tiên. Phiên bản hiện tại không tự cắt khoảng trắng, bỏ dấu nháy, xử lý `export` hay mở rộng biến môi trường.

## Tích hợp với dự án CMake khác

Đặt dự án này trong mã nguồn của ứng dụng (ví dụ `external/dotenv-cpp`), rồi thêm vào `CMakeLists.txt` của ứng dụng:

```cmake
add_subdirectory(external/dotenv-cpp)

add_executable(my-app main.cpp)
target_link_libraries(my-app PRIVATE dotenv::dotenv)
```

Target `dotenv::dotenv` tự cung cấp thư mục header `include/` và yêu cầu C++20 cho ứng dụng liên kết với nó.

## Cấu trúc dự án

```text
include/env.h          Giao diện lớp Env
src/env.cpp            Cài đặt bộ đọc .env
examples/basic.cpp     Chương trình minh họa
examples/.env          Dữ liệu đầu vào cho ví dụ
CMakeLists.txt         Cấu hình build thư viện
```
