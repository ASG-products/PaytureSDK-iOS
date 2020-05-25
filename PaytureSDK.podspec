#
# Be sure to run `pod lib lint PaytureSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PaytureSDK'
  s.version          = '0.1.6'
  s.summary          = 'Library for work with Payture payments for mobile apps'

#  s.description      = <<-DESC
#TODO: Add long description of the pod here.
#                       DESC

  s.homepage         = 'https://payture.com/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Ilya Fedorov' => 'ilya.fedorov@antares-software.ru' }
  s.source           = { :git => 'https://github.com/ASG-products/PaytureSDK-iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.ios.vendored_frameworks = 'PaytureSDK.framework'
  
  s.dependency 'AFNetworking', '~> 4.0'
end
