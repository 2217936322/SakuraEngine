include_directories(${Vulkan_INCLUDES})
 
find_file(SpecificTimerImpl GpuTimer.cpp *GpuTimer*.cpp 
    PATHS ${CMAKE_CURRENT_SOURCE_DIR})
     
if(SpecificTimerImpl)
else(SpecificTimerImpl)
set(SpecificTimerImpl ../CGD/GpuTimer.cpp) 
endif(SpecificTimerImpl)

find_package(unofficial-vulkan-memory-allocator CONFIG REQUIRED)

if(${SAKURA_UNITY_BUILD})
add_library(CGD_Vulkan  
    STATIC  
    CGDVk_All.cpp
)
else()
add_library(CGD_Vulkan  
    STATIC    
    CGD_Vulkan.cpp
    CommandObjects/CommandBufferVk.cpp
    CommandObjects/CommandQueueVk.cpp
    ResourceObjects/GpuResourceVk.cpp
    ResourceObjects/ResourceViewVk.cpp
    ResourceObjects/ShaderVk.cpp
    ResourceObjects/VBIBViewVk.cpp
    GraphicsObjects/SwapChainVk.cpp
    GraphicsObjects/GraphicsPipelineVk.cpp
    GraphicsObjects/ComputePipelineVk.cpp
    GraphicsObjects/RenderPassVk.cpp
    GraphicsObjects/RootSignatureVk.cpp
    GraphicsObjects/FenceVk.cpp
)
endif()

target_link_libraries(CGD_Vulkan
Core Vulkan::Vulkan 
unofficial::vulkan-memory-allocator::vulkan-memory-allocator)