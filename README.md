# SakuraEngine
A Cross-Platform Mordern Game Engine.

  * Package Management
    * Conan √
  * Construct
    * CMake √
  * UnitTest
    * GTest √
  * PluginManager √
    * [SPA](SPA/)(SakuraPluginAdministrator): Plugin Administrator to manage plugins
      * Based on Python Batcher.
      * Load/Unload plugins in order described with json file, by Dependency Graph.
      * Dispatch and handle requesting from plugins/modules.
  * [Core](SakuraEngine/Core/) √ 
    * Platform Defination √(Win32/Linux)
    * EngineUtils(EnvQuery√, Timer√, T2StringCaster√, Path Operation√, Thread...)
    * Math √(Eigen3)
    * Efficient Streaming
    * Quik String √(pmr::string and caster)
  * MemoryManagement
    * Allocator 🚧
    * STL Container Wrappers √
  * Script
    * Mono?
    * Auto-Binding / Binding Machine
  * Graphics: [CGD](SakuraEngine/GraphicsInterface) 🚧
    * GraphicsUtils
      * GraphicsProfiling(GpuTimer...) 🚧
    * TargetGraphicsInterface 🚧
      * Vulkan 🚧
      * D3D12 🚧
      * Metal
    * CommonGraphicsDevice
      * Async-Compute Command Context
      * RayTracing Layer/Device
      * Sharp Text Renderer
      * 2D Renderer
    * GraphicsDispatcher
      * ResourceManagement
      * Easy Param Binding
      * Multi-Thread Dispatching
      * Data-Driven pipeline
    * RenderPipeline
      * PBR Shading Models
      * F+ Shading
      * Culling
      * Shadowing 
      * SSAO(GTAO/HBAO+)
      * RTAO
      * DDGI
      * Paricle Effect
      * ...
  * EngineDrivers
      * FrameGraph/RenderGraph
      * TaskFlow/JobSystem
  * Scene
      * Node-Based Scene √
      * Serialization
      * Flexible assembling 
  * Profiling
    * PIX
    


