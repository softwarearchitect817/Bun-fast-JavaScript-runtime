export function family() {
  return Promise.resolve(null);
}

export function familySync() {
  return null;
}

export const GLIBC = "glibc";
export const MUSL = "musl";

export function versionAsync() {
  return Promise.resolve(version());
}

export function version() {
  return null;
}

export function isNonGlibcLinuxSync() {
  return false;
}

export function isNonGlibcLinux() {
  return Promise.resolve(isNonGlibcLinuxSync());
}
