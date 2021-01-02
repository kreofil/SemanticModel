# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Установка переменной со списком исходников
set(SOURCE_LIB 
    # headers
    artefact.h
    const.h
    context.h
    creator.h
    ilist.h
    import.h
    instruction.h
    module.h
    nametable.h
    operand.h
    procedure.h
    type.h
    variable.h
    
    #sources
    artefact.cpp
    const.cpp
    context.cpp
    creator.cpp
    ilist.cpp
    import.cpp
    instruction.cpp
    module.cpp
    nametable.cpp
    operand.cpp
    procedure.cpp
    type.cpp
    variable.cpp
)

add_library(smodel STATIC ${SOURCE_LIB})   # Создание статической библиотеки
