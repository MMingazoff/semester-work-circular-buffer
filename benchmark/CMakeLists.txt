# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(enqueue_benchmark enqueue_benchmark.cpp)
add_executable(dequeue_benchmark dequeue_benchmark.cpp)
add_executable(enqueue_full_bench enqueue_full_bench.cpp)
add_executable(dequeue_full_bench dequeue_full_bench.cpp)


# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(enqueue_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(dequeue_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(enqueue_full_bench PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(dequeue_full_bench PRIVATE project_paths project_warnings ${PROJECT_NAME})