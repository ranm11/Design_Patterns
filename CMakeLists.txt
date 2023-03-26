cmake_minimum_required(VERSION 2.8.9)

message(" ${DP_Type}" Design pattern)
if(${DP_Type} STREQUAL "OBSERVER")

project (observer)
add_executable(observer)
set(observer_files 
    observer/observer.cpp
    observer/subject.cpp
    observer/main.cpp)
    target_sources(observer PRIVATE ${observer_files})

  elseif(${DP_Type} STREQUAL "BARRIER")  
    project (syncBarrier)
    add_executable(syncBarrier)
    set(sync_files syncBarrier/syncBarrier.cpp)
    target_sources(syncBarrier PRIVATE ${sync_files})
  elseif(${DP_Type} STREQUAL "THREAD_SYNC")  
    project (threadSync)
    add_executable(threadSync)
    set(sync_files threadSync/threadSync.cpp)
    target_sources(threadSync PRIVATE ${sync_files})
  endif()