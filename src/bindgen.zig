pub const bindgen = true;

pub const main = @import("./bun.js/bindings/bindings-generator.zig").main;
pub export fn PLCrashReportHandler(_: ?*anyopaque) void {}
pub export fn mkdirp(_: ?*anyopaque) void {}
