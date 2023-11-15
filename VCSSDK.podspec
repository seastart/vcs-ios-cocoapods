#
# Be sure to run `pod lib lint VCSSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'VCSSDK'
  s.version          = '1.3.22-audioOptimize.4'
  s.summary          = '视频会议SDK'
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'http://code.zaoing.com/meeting/VCSSDK-iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'SailorGa' => 'ljia789@gmail.com' }
  s.source           = { :git => 'http://code.zaoing.com/meeting/VCSSDK-iOS.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  # 指定支持平台
  s.ios.deployment_target = '9.0'

  # 设置包含静态库框架(注意：不能写在subspec子模块中)
  s.static_framework = true
  # 依赖系统Frameworks库(采用weak link弱链接)
  s.weak_frameworks = 'SystemConfiguration', 'Accelerate', 'AVFoundation', 'QuartzCore', 'CoreGraphics', 'CoreMedia', 'CoreAudio', 'CoreVideo', 'CoreML', 'OpenGLES', 'Security', 'CFNetwork', 'UIKit', 'Foundation', 'ReplayKit', 'PushKit', 'CoreTelephony'
  # 依赖系统Librarie库
  s.libraries = 'icucore', 'c', 'z', 'iconv', 'bz2', 'c++', 'resolv'

  # 依赖开源库
  s.dependency 'MMKV'
  s.dependency 'Protobuf'
  s.dependency 'SSZipArchive', '>= 2.4.3'
  s.dependency 'AFNetworking', '>= 4.0.0'
  
  # 依赖本地Frameworks库
  s.vendored_frameworks = 'VCSSDK/Depend/*.framework'
  
  # 引用资源
  s.resource = 'VCSSDK/Resources/*.bundle'
  
  # 设置CPP符号，以便代码知道美颜组件导入
  s.user_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) VCS_USE_PROTOBUF_BEAUTY_IMPORTS=1' }
  s.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) VCS_USE_PROTOBUF_BEAUTY_IMPORTS=1' }
end
