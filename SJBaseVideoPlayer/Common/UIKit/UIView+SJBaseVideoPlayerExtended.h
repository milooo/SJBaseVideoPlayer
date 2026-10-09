//
//  UIView+SJBaseVideoPlayerExtended.h
//  SJBaseVideoPlayer
//
//  Created by 畅三江 on 2019/11/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#define KWindow ({\
    UIWindow *window = nil;\
    if (@available(iOS 13.0, *)) {\
        for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {\
            if (scene.activationState == UISceneActivationStateForegroundActive && [scene isKindOfClass:[UIWindowScene class]]) {\
                for (UIWindow *w in ((UIWindowScene *)scene).windows) {\
                    if (w.isKeyWindow) {\
                        window = w;\
                        break;\
                    }\
                }\
            }\
            if (window) break;\
        }\
    }\
    if (!window) {\
        window = [UIApplication sharedApplication].windows.firstObject;\
        if (!window.isKeyWindow) {\
             UIWindow *keyWindow = nil;\
             _Pragma("clang diagnostic push") \
             _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
             keyWindow = [UIApplication sharedApplication].keyWindow; \
             _Pragma("clang diagnostic pop") \
             if (keyWindow) window = keyWindow;\
        }\
    }\
    window;\
})
@interface UIView (SJBaseVideoPlayerExtended)

- (BOOL)isViewAppeared:(UIView *_Nullable)childView insets:(UIEdgeInsets)insets;

- (CGRect)intersectionWithView:(UIView *)view insets:(UIEdgeInsets)insets;

- (__kindof UIResponder *_Nullable)lookupResponderForClass:(Class)cls;

- (__kindof UIView *_Nullable)viewWithProtocol:(Protocol *)protocol tag:(NSInteger)tag;

- (BOOL)isViewAppearedWithProtocol:(Protocol *)protocol tag:(NSInteger)tag insets:(UIEdgeInsets)insets;

@property (nonatomic) CGFloat sj_x;
@property (nonatomic) CGFloat sj_y;
@property (nonatomic) CGFloat sj_w;
@property (nonatomic) CGFloat sj_h;
@property (nonatomic) CGSize sj_size;
@end

@interface NSObject (SJBaseVideoPlayerExtended)
- (__kindof UIView *_Nullable)subviewForSelector:(SEL)selector;
@end
NS_ASSUME_NONNULL_END
